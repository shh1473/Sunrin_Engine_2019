#include "SR_PCH.h"

#include "SR_Transform.h"
#include "SR_Entity.h"

namespace SunrinEngine
{

	SR_Transform::SR_Transform(SR_Entity * owner) :
		SR_Component(owner),
		m_worldPosition	{},
		m_worldRotation	{},
		m_worldScale	{},
		m_worldMatrix	{},
		m_localPosition	{},
		m_localRotation	{},
		m_localScale	{},
		m_localMatrix	{},
		m_parentMatrix	{}
	{
		ResetTransform();
	}

	bool SR_Transform::Update()
	{
		if (m_localPosition.Check() ||
			m_localRotation.Check() ||
			m_localScale.Check())
		{
			m_localMatrix.SetValue(SR_Matrix4x4::CreateScaleMatrix(m_localScale.GetValue().m_float3));
			m_localMatrix.Multiply(SR_Matrix4x4::CreateRotationMatrix(m_localRotation.GetValue().m_float3));
			m_localMatrix.Multiply(SR_Matrix4x4::CreateTranslationMatrix(m_localPosition.GetValue().m_float3));

			m_localPosition.Reset();
			m_localRotation.Reset();
			m_localScale.Reset();
		}

		if (m_localMatrix.Check() ||
			m_parentMatrix.Check())
		{
			m_worldPosition = m_localPosition.GetValue();
			m_worldRotation = m_localRotation.GetValue();
			m_worldScale = m_localScale.GetValue();
			m_worldMatrix = m_localMatrix.GetValue();

			if (GetOwner()->GetParent())
			{
				m_worldPosition += GetOwner()->GetParent()->GetTransform()->m_worldPosition;
				m_worldRotation += GetOwner()->GetParent()->GetTransform()->m_worldRotation;
				m_worldScale *= GetOwner()->GetParent()->GetTransform()->m_worldScale;
				m_worldMatrix *= m_parentMatrix.GetValue();
			}

			for (auto & iter : GetOwner()->GetChildren())
			{
				iter.second->GetTransform()->m_parentMatrix.SetValue(m_worldMatrix);
			}

			m_localMatrix.Reset();
			m_parentMatrix.Reset();
		}

		return true;
	}

	void SR_Transform::ResetTransform()
	{
		m_worldPosition.m_x = 0.0f;
		m_worldPosition.m_y = 0.0f;
		m_worldPosition.m_z = 0.0f;
		m_worldRotation.m_x = 0.0f;
		m_worldRotation.m_y = 0.0f;
		m_worldRotation.m_z = 0.0f;
		m_worldScale.m_x = 1.0f;
		m_worldScale.m_y = 1.0f;
		m_worldScale.m_z = 1.0f;
		m_worldMatrix = SR_Matrix4x4::m_IDENTITY;

		m_localPosition.Set(0.0f, 0.0f, 0.0f);
		m_localRotation.Set(0.0f, 0.0f, 0.0f);
		m_localScale.Set(1.0f, 1.0f, 1.0f);
		m_localMatrix.Set(SR_Matrix4x4::m_IDENTITY);
		m_parentMatrix.Set(SR_Matrix4x4::m_IDENTITY);

		m_localPosition.Reset();
		m_localRotation.Reset();
		m_localScale.Reset();
		m_localMatrix.Reset();
		m_parentMatrix.Reset();
	}

}