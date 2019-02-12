#include "SR_PCH.h"

#include "SR_Camera.h"
#include "SR_Math.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_CommonCamera::SR_CommonCamera(SR_Entity * owner) :
		SR_Component(owner),
		m_look						{ 0.0f, 0.0f, 0.0f },
		m_up						{ 0.0f, 0.0f, 0.0f },
		m_right						{ 0.0f, 0.0f, 0.0f },
		m_rotationMatrix			{ SR_Matrix4x4::m_IDENTITY },
		m_viewMatrix				{ SR_Matrix4x4::m_IDENTITY },
		m_projectionMatrix			{ SR_Matrix4x4::m_IDENTITY },
		m_cameraParameterSet		{ nullptr },
		m_isEnableFrustumCulling	{ false }
	{
		m_isPerspective.SetValue(true);
		m_fieldOfView.SetValue(SR_Math::PI() * 0.25f);
		m_nearZ.SetValue(1.0f);
		m_farZ.SetValue(1000.0f);
		m_viewWidth.SetValue(1024.0f);
		m_viewHeight.SetValue(1024.0f);
		m_positionCheck.Set(0.0f, 0.0f, 0.0f);
		m_rotationCheck.Set(0.0f, 0.0f, 0.0f);

		m_isPerspective.Reset();
		m_fieldOfView.Reset();
		m_nearZ.Reset();
		m_farZ.Reset();
		m_viewWidth.Reset();
		m_viewHeight.Reset();
		m_positionCheck.Reset();
		m_rotationCheck.Reset();

		UpdateViewMatrix();
		UpdateProjMatrix();
	}

	bool SR_CommonCamera::Update()
	{
		bool isMatrixChanged{ false };

		m_positionCheck.SetValue(GetOwner()->GetTransform()->GetWorldPosition());
		m_rotationCheck.SetValue(GetOwner()->GetTransform()->GetWorldRotation());

		if (m_positionCheck.Check() ||
			m_rotationCheck.Check())
		{
			UpdateViewMatrix();

			isMatrixChanged = true;

			m_positionCheck.Reset();
			m_rotationCheck.Reset();
		}

		if (m_isPerspective.Check() ||
			m_fieldOfView.Check() ||
			m_nearZ.Check() ||
			m_farZ.Check() ||
			m_viewWidth.Check() ||
			m_viewHeight.Check())
		{
			UpdateProjMatrix();

			isMatrixChanged = true;

			m_isPerspective.Reset();
			m_fieldOfView.Reset();
			m_nearZ.Reset();
			m_farZ.Reset();
			m_viewWidth.Reset();
			m_viewHeight.Reset();
		}

		if (isMatrixChanged)
		{
			UpdateFrustumPlanes();
		}

		return true;
	}

	void SR_CommonCamera::Ready()
	{
		m_cameraParameterSet->Apply();

		for (unsigned i{ 0 }; i < SR_MAX_THREAD_COUNT; ++i)
		{
			GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().Apply(
				m_cameraParameterSet->GetIsBindRenderTargetViewAndDepthStencilView(),
				m_cameraParameterSet->GetIsBindDepthStencilState(),
				m_cameraParameterSet->GetIsBindBlendState());

			GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetRasterizerStage().Apply(
				m_cameraParameterSet->GetIsBindRasterizerState(),
				m_cameraParameterSet->GetIsBindViewport(),
				m_cameraParameterSet->GetIsBindScissorRect());
		}

		GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(0).GetOutputMergerStage().ClearViews();
	}

	bool SR_CommonCamera::CheckFrustum(const SR_Vector3 & worldPosition, float radius)
	{
		return
			(SR_Plane::DotCoord(m_frustumPlanes[0], worldPosition.m_float3) > -radius) &&
			(SR_Plane::DotCoord(m_frustumPlanes[1], worldPosition.m_float3) > -radius) &&
			(SR_Plane::DotCoord(m_frustumPlanes[2], worldPosition.m_float3) > -radius) &&
			(SR_Plane::DotCoord(m_frustumPlanes[3], worldPosition.m_float3) > -radius) &&
			(SR_Plane::DotCoord(m_frustumPlanes[4], worldPosition.m_float3) > -radius) &&
			(SR_Plane::DotCoord(m_frustumPlanes[5], worldPosition.m_float3) > -radius);
	}

	void SR_CommonCamera::UpdateViewMatrix()
	{
		m_look.m_x = 0.0f;
		m_look.m_y = 0.0f;
		m_look.m_z = 1.0f;
		m_up.m_x = 0.0f;
		m_up.m_y = 1.0f;
		m_up.m_z = 0.0f;

		m_rotationMatrix = SR_Matrix4x4::CreateRotationMatrix(m_rotationCheck.GetValue().m_float3);

		m_look = SR_Vector3::TransformNormal(m_look, m_rotationMatrix.m_float4x4);
		m_look = SR_Vector3::Normalize(m_look);

		m_up = SR_Vector3::TransformNormal(m_up, m_rotationMatrix.m_float4x4);
		m_up = SR_Vector3::Normalize(m_up);

		m_right = SR_Vector3::Cross(m_up, m_look);
		m_right = SR_Vector3::Normalize(m_right);

		m_viewMatrix = SR_Matrix4x4::CreateLookAt(
			m_positionCheck.GetValue().m_float3,
			SR_Vector3(m_positionCheck.GetValue() + m_look).m_float3,
			m_up.m_float3);
	}

	void SR_CommonCamera::UpdateProjMatrix()
	{
		if (m_isPerspective.GetValue())
		{
			m_projectionMatrix = SR_Matrix4x4::CreatePerspectiveFieldOfView(
				m_fieldOfView.GetValue(),
				m_viewWidth.GetValue() / m_viewHeight.GetValue(),
				m_nearZ.GetValue(),
				m_farZ.GetValue());
		}
		else
		{
			m_projectionMatrix = SR_Matrix4x4::CreateOrthographic(
				m_viewWidth.GetValue(),
				m_viewHeight.GetValue(),
				m_nearZ.GetValue(),
				m_farZ.GetValue());
		}
	}

	void SR_CommonCamera::UpdateFrustumPlanes()
	{
		SR_Matrix4x4 frustumprojectionMatrix{ m_projectionMatrix };
		float zMin{ -m_projectionMatrix.m_32 / m_projectionMatrix.m_22 };
		float r{ m_farZ.GetValue() / (m_farZ.GetValue() - zMin) };

		m_frustumMatrix = m_viewMatrix * frustumprojectionMatrix;

		m_frustumPlanes[0].m_x = m_frustumMatrix.m_14 + m_frustumMatrix.m_11;
		m_frustumPlanes[0].m_y = m_frustumMatrix.m_24 + m_frustumMatrix.m_21;
		m_frustumPlanes[0].m_z = m_frustumMatrix.m_34 + m_frustumMatrix.m_31;
		m_frustumPlanes[0].m_w = m_frustumMatrix.m_44 + m_frustumMatrix.m_41;

		m_frustumPlanes[1].m_x = m_frustumMatrix.m_14 - m_frustumMatrix.m_11;
		m_frustumPlanes[1].m_y = m_frustumMatrix.m_24 - m_frustumMatrix.m_21;
		m_frustumPlanes[1].m_z = m_frustumMatrix.m_34 - m_frustumMatrix.m_31;
		m_frustumPlanes[1].m_w = m_frustumMatrix.m_44 - m_frustumMatrix.m_41;

		m_frustumPlanes[2].m_x = m_frustumMatrix.m_14 + m_frustumMatrix.m_12;
		m_frustumPlanes[2].m_y = m_frustumMatrix.m_24 + m_frustumMatrix.m_22;
		m_frustumPlanes[2].m_z = m_frustumMatrix.m_34 + m_frustumMatrix.m_32;
		m_frustumPlanes[2].m_w = m_frustumMatrix.m_44 + m_frustumMatrix.m_42;

		m_frustumPlanes[3].m_x = m_frustumMatrix.m_14 - m_frustumMatrix.m_12;
		m_frustumPlanes[3].m_y = m_frustumMatrix.m_24 - m_frustumMatrix.m_22;
		m_frustumPlanes[3].m_z = m_frustumMatrix.m_34 - m_frustumMatrix.m_32;
		m_frustumPlanes[3].m_w = m_frustumMatrix.m_44 - m_frustumMatrix.m_42;

		m_frustumPlanes[4].m_x = m_frustumMatrix.m_14 + m_frustumMatrix.m_13;
		m_frustumPlanes[4].m_y = m_frustumMatrix.m_24 + m_frustumMatrix.m_23;
		m_frustumPlanes[4].m_z = m_frustumMatrix.m_34 + m_frustumMatrix.m_33;
		m_frustumPlanes[4].m_w = m_frustumMatrix.m_44 + m_frustumMatrix.m_43;

		m_frustumPlanes[5].m_x = m_frustumMatrix.m_14 - m_frustumMatrix.m_13;
		m_frustumPlanes[5].m_y = m_frustumMatrix.m_24 - m_frustumMatrix.m_23;
		m_frustumPlanes[5].m_z = m_frustumMatrix.m_34 - m_frustumMatrix.m_33;
		m_frustumPlanes[5].m_w = m_frustumMatrix.m_44 - m_frustumMatrix.m_43;

		SR_Plane::Normalize(m_frustumPlanes[0].m_plane);
		SR_Plane::Normalize(m_frustumPlanes[1].m_plane);
		SR_Plane::Normalize(m_frustumPlanes[2].m_plane);
		SR_Plane::Normalize(m_frustumPlanes[3].m_plane);
		SR_Plane::Normalize(m_frustumPlanes[4].m_plane);
		SR_Plane::Normalize(m_frustumPlanes[5].m_plane);
	}

	SR_ForwardCamera::SR_ForwardCamera(SR_Entity * owner) :
		SR_CommonCamera(owner)
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().AddForwardCamera(this);
	}

	SR_ForwardCamera::~SR_ForwardCamera()
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().RemoveForwardCamera(this);
	}

	SR_DeferredCamera::SR_DeferredCamera(SR_Entity * owner) :
		SR_CommonCamera(owner)
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().AddDeferredCamera(this);
	}

	SR_DeferredCamera::~SR_DeferredCamera()
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().RemoveDeferredCamera(this);
	}

	SR_PackingCamera::SR_PackingCamera(SR_Entity * owner) :
		SR_CommonCamera(owner)
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().AddPackingCamera(this);
	}

	SR_PackingCamera::~SR_PackingCamera()
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().RemovePackingCamera(this);
	}

}