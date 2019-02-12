#include "SR_PCH.h"

#include "SR_UITransform.h"
#include "SR_UI.h"

namespace SunrinEngine
{

	SR_UITransform::SR_UITransform(SR_UI * owner) :
		SR_UIComponent(owner),
		m_worldPivotOffset	{},
		m_worldCenter		{},
		m_worldPosition		{},
		m_worldScale		{},
		m_worldSkew			{},
		m_worldRotation		{},
		m_localPivotOffset	{},
		m_localCenter		{},
		m_localPosition		{},
		m_localScale		{},
		m_localSkew			{},
		m_localRotation		{},
		m_worldMatrix		{},
		m_localMatrix		{},
		m_parentMatrix		{}
	{
		ResetTransform();
	}

	bool SR_UITransform::Update()
	{
		if (m_localPivotOffset.Check() ||
			m_localCenter.Check() ||
			m_localPosition.Check() ||
			m_localScale.Check() ||
			m_localSkew.Check() ||
			m_localRotation.Check())
		{
			m_localMatrix.Set(SR_Matrix3x2::CreateTranslationMatrix(m_localPivotOffset.GetValue().m_float2));
			m_localMatrix.Multiply(SR_Matrix3x2::CreateSkewMatrix(m_localSkew.GetValue().m_float2, m_localCenter.GetValue().m_float2));
			m_localMatrix.Multiply(SR_Matrix3x2::CreateScaleMatrix(m_localScale.GetValue().m_float2, m_localCenter.GetValue().m_float2));
			m_localMatrix.Multiply(SR_Matrix3x2::CreateRotationMatrix(m_localRotation.GetValue(), m_localCenter.GetValue().m_float2));
			m_localMatrix.Multiply(SR_Matrix3x2::CreateTranslationMatrix(m_localPosition.GetValue().m_float2));

			m_localPivotOffset.Reset();
			m_localCenter.Reset();
			m_localPosition.Reset();
			m_localScale.Reset();
			m_localSkew.Reset();
			m_localRotation.Reset();
		}

		if (m_localMatrix.Check() ||
			m_parentMatrix.Check())
		{
			m_worldPivotOffset = m_localPivotOffset.GetValue();
			m_worldPosition = m_localPosition.GetValue();
			m_worldRotation = m_localRotation.GetValue();
			m_worldScale = m_localScale.GetValue();
			m_worldSkew = m_localSkew.GetValue();
			m_worldMatrix = m_localMatrix.GetValue();

			if (GetOwner()->GetParent())
			{
				m_worldPivotOffset += GetOwner()->GetParent()->GetTransform()->m_worldPivotOffset;
				m_worldPosition += GetOwner()->GetParent()->GetTransform()->m_worldPosition;
				m_worldScale *= GetOwner()->GetParent()->GetTransform()->m_worldScale;
				m_worldSkew += GetOwner()->GetParent()->GetTransform()->m_worldSkew;
				m_worldRotation += GetOwner()->GetParent()->GetTransform()->m_worldRotation;
				m_worldMatrix *= m_parentMatrix.GetValue();
			}

			for (auto & childrenIter : GetOwner()->GetChildren())
			{
				childrenIter.second->GetTransform()->m_parentMatrix.SetValue(m_worldMatrix);
			}

			m_localMatrix.Reset();
			m_parentMatrix.Reset();
		}

		return true;
	}

	void SR_UITransform::ResetTransform()
	{
		m_worldPivotOffset = SR_Vector2::m_ZERO;
		m_worldCenter = SR_Vector2::m_ZERO;
		m_worldPosition = SR_Vector2::m_ZERO;
		m_worldScale = SR_Vector2::m_ONE;
		m_worldSkew = SR_Vector2::m_ZERO;
		m_worldRotation = 0.0f;

		m_localPivotOffset.Set(SR_Vector2::m_ZERO);
		m_localCenter.Set(SR_Vector2::m_ZERO);
		m_localPosition.Set(SR_Vector2::m_ZERO);
		m_localScale.Set(SR_Vector2::m_ONE);
		m_localSkew.Set(SR_Vector2::m_ZERO);
		m_localRotation.Set(0.0f);
		m_worldMatrix = SR_Matrix3x2::m_IDENTITY;
		m_localMatrix.Set(SR_Matrix3x2::m_IDENTITY);
		m_parentMatrix.Set(SR_Matrix3x2::m_IDENTITY);

		m_localPivotOffset.Reset();
		m_localCenter.Reset();
		m_localPosition.Reset();
		m_localScale.Reset();
		m_localRotation.Reset();
		m_localMatrix.Reset();
		m_parentMatrix.Reset();
	}

}