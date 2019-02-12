#pragma once

#include "SR_Component.h"
#include "SR_DirtyFlagMath.h"
#include "SR_CameraParameterSet.h"
#include "SR_Plane.h"

namespace SunrinEngine
{

	class SR_CommonCamera : public SR_Component
	{
	public:
		explicit SR_CommonCamera(SR_Entity * owner);

		virtual bool Update() override;

		void Ready();

		bool CheckFrustum(const SR_Vector3 & worldPosition, float radius);

		void SetIsPerspective(bool isPersp) { m_isPerspective.SetValue(isPersp); }
		void SetFieldOfView(float fieldOfView) { m_fieldOfView.SetValue(fieldOfView); }
		void SetNearZ(float nearZ) { m_nearZ.SetValue(nearZ); }
		void SetFarZ(float farZ) { m_farZ.SetValue(farZ); }
		void SetViewWidth(float width) { m_viewWidth.SetValue(width); }
		void SetViewHeight(float height) { m_viewHeight.SetValue(height); }
		void AddViewWidth(float width) { m_viewWidth.SetValue(m_viewWidth.GetValue() + width); }
		void AddViewHeight(float height) { m_viewHeight.SetValue(m_viewHeight.GetValue() + height); }
		void SetIsEnableFrustumCulling(bool isEnable) { m_isEnableFrustumCulling = isEnable; }
		void SetCameraParameterSet(SR_CameraParameterSet * cameraParameterSet) { m_cameraParameterSet = cameraParameterSet; }

		const SR_Vector3 & GetLookDirection() const noexcept { return m_look; }
		const SR_Vector3 & GetRightDirection() const noexcept { return m_right; }
		const SR_Matrix4x4 & GetViewMatrix() const noexcept { return m_viewMatrix; }
		const SR_Matrix4x4 & GetProjMatrix() const noexcept { return m_projectionMatrix; }
		float GetNearZ() const noexcept { return m_nearZ.GetValue(); }
		float GetFarZ() const noexcept { return m_farZ.GetValue(); }
		float GetViewWidth() const noexcept { return m_viewWidth.GetValue(); }
		float GetViewHeight() const noexcept { return m_viewHeight.GetValue(); }
		bool GetIsEnableFrustumCulling() const noexcept { return m_isEnableFrustumCulling; }
		SR_CameraParameterSet * GetCameraParameterSet() const noexcept { return m_cameraParameterSet; }

	private:
		void UpdateViewMatrix();
		void UpdateProjMatrix();
		void UpdateFrustumPlanes();

	private:
		SR_Vector3 m_look;
		SR_Vector3 m_up;
		SR_Vector3 m_right;
		SR_Matrix4x4 m_rotationMatrix;
		SR_Matrix4x4 m_viewMatrix;
		SR_Matrix4x4 m_projectionMatrix;
		SR_DirtyFlag<bool> m_isPerspective;
		SR_DirtyFlag<float> m_fieldOfView;
		SR_DirtyFlag<float> m_nearZ;
		SR_DirtyFlag<float> m_farZ;
		SR_DirtyFlag<float> m_viewWidth;
		SR_DirtyFlag<float> m_viewHeight;
		SR_DirtyFlagVector3 m_positionCheck;
		SR_DirtyFlagVector3 m_rotationCheck;

		bool m_isEnableFrustumCulling;
		SR_Plane m_frustumPlanes[6];
		SR_Matrix4x4 m_frustumMatrix;

		SR_CameraParameterSet * m_cameraParameterSet;

	};

	class SR_ForwardCamera : public SR_CommonCamera
	{
	public:
		explicit SR_ForwardCamera(SR_Entity * owner);
		~SR_ForwardCamera();

	};

	class SR_DeferredCamera : public SR_CommonCamera
	{
	public:
		explicit SR_DeferredCamera(SR_Entity * owner);
		~SR_DeferredCamera();

	};

	class SR_PackingCamera : public SR_CommonCamera
	{
	public:
		explicit SR_PackingCamera(SR_Entity * owner);
		~SR_PackingCamera();

	};

}