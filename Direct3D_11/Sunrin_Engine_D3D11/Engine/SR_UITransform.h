#pragma once

#include "SR_UIComponent.h"
#include "SR_DirtyFlagMath.h"

namespace SunrinEngine
{

	class SR_UITransform : public SR_UIComponent
	{
	public:
		explicit SR_UITransform(SR_UI * owner);

		virtual bool Update() override;

		void ResetTransform();

		void SetPivotOffset(const SR_Vector2 & pivotOffset) { m_localPivotOffset.Set(pivotOffset); }
		void SetPivotOffset(float x, float y) { m_localPivotOffset.Set(x, y); }
		void SetPivotOffsetX(float x) { m_localPivotOffset.SetX(x); }
		void SetPivotOffsetY(float y) { m_localPivotOffset.SetY(y); }
		void SetCenter(const SR_Vector2 & center) { m_localCenter.Set(center); }
		void SetCenter(float x, float y) { m_localCenter.Set(x, y); }
		void SetCenterX(float x) { m_localCenter.SetX(x); }
		void SetCenterY(float y) { m_localCenter.SetY(y); }
		void SetPosition(const SR_Vector2 & position) { m_localPosition.Set(position); }
		void SetPosition(float x, float y) { m_localPosition.Set(x, y); }
		void SetPositionX(float x) { m_localPosition.SetX(x); }
		void SetPositionY(float y) { m_localPosition.SetY(y); }
		void SetSkew(const SR_Vector2 & skew) { m_localSkew.Set(skew); }
		void SetSkew(float x, float y) { m_localSkew.Set(x, y); }
		void SetSkewX(float x) { m_localSkew.SetX(x); }
		void SetSkewY(float y) { m_localSkew.SetY(y); }
		void SetScale(const SR_Vector2 & scale) { m_localScale.Set(scale); }
		void SetScale(float x, float y) { m_localScale.Set(x, y); }
		void SetScaleX(float x) { m_localScale.SetX(x); }
		void SetScaleY(float y) { m_localScale.SetY(y); }
		void SetRotation(float rotation) { m_localRotation.Set(rotation); }

		void AddPivotOffset(const SR_Vector2 & pivotOffset) { m_localPivotOffset.Add(pivotOffset); }
		void AddPivotOffset(float x, float y) { m_localPivotOffset.Add(x, y); }
		void AddPivotOffsetX(float x) { m_localPivotOffset.AddX(x); }
		void AddPivotOffsetY(float y) { m_localPivotOffset.AddY(y); }
		void AddCenter(const SR_Vector2 & center) { m_localCenter.Add(center); }
		void AddCenter(float x, float y) { m_localCenter.Add(x, y); }
		void AddCenterX(float x) { m_localCenter.AddX(x); }
		void AddCenterY(float y) { m_localCenter.AddY(y); }
		void AddPosition(const SR_Vector2 & position) { m_localPosition.Add(position); }
		void AddPosition(float x, float y) { m_localPosition.Add(x, y); }
		void AddPositionX(float x) { m_localPosition.AddX(x); }
		void AddPositionY(float y) { m_localPosition.AddY(y); }
		void AddScale(const SR_Vector2 & scale) { m_localScale.Add(scale); }
		void AddScale(float x, float y) { m_localScale.Add(x, y); }
		void AddScaleX(float x) { m_localScale.AddX(x); }
		void AddScaleY(float y) { m_localScale.AddY(y); }
		void AddSkew(const SR_Vector2 & scale) { m_localSkew.Add(scale); }
		void AddSkew(float x, float y) { m_localSkew.Add(x, y); }
		void AddSkewX(float x) { m_localSkew.AddX(x); }
		void AddSkewY(float y) { m_localSkew.AddY(y); }
		void AddRotation(float rotation) { m_localRotation.Add(rotation); }

		const SR_Vector2 & GetLocalPivotOffset() const noexcept { return m_localPivotOffset.GetValue(); }
		const SR_Vector2 & GetLocalCenter() const noexcept { return m_localCenter.GetValue(); }
		const SR_Vector2 & GetLocalPosition() const noexcept { return m_localPosition.GetValue(); }
		float GetLocalRotation() const noexcept { return m_localRotation.GetValue(); }
		const SR_Vector2 & GetLocalScale() const noexcept { return m_localScale.GetValue(); }
		const SR_Vector2 & GetWorldPosition() const noexcept { return m_worldPosition; }
		float GetWorldRotation() const noexcept { return m_worldRotation; }
		const SR_Vector2 & GetWorldScale() const noexcept { return m_worldScale; }
		const SR_Matrix3x2 & GetWorldMatrix() const noexcept { return m_worldMatrix; }
		const SR_Matrix3x2 & GetLocalMatrix() const noexcept { return m_localMatrix.GetValue(); }
		const SR_Matrix3x2 & GetParentMatrix() const noexcept { return m_parentMatrix.GetValue(); }
		const SR_Matrix3x2 * GetWorldMatrixAddressOf() const noexcept { return &m_worldMatrix; }
		const SR_Matrix3x2 * GetLocalMatrixAddressOf() const noexcept { return m_localMatrix.GetAddressOf(); }
		const SR_Matrix3x2 * GetParentMatrixAddressOf() const noexcept { return m_parentMatrix.GetAddressOf(); }

	private:
		SR_Vector2 m_worldPivotOffset;
		SR_Vector2 m_worldCenter;
		SR_Vector2 m_worldPosition;
		SR_Vector2 m_worldScale;
		SR_Vector2 m_worldSkew;
		float m_worldRotation;
		SR_DirtyFlagVector2 m_localPivotOffset;
		SR_DirtyFlagVector2 m_localCenter;
		SR_DirtyFlagVector2 m_localPosition;
		SR_DirtyFlagVector2 m_localScale;
		SR_DirtyFlagVector2 m_localSkew;
		SR_DirtyFlagVector1 m_localRotation;
		SR_Matrix3x2 m_worldMatrix;
		SR_DirtyFlagMatrix3x2 m_localMatrix;
		SR_DirtyFlagMatrix3x2 m_parentMatrix;

	};

}