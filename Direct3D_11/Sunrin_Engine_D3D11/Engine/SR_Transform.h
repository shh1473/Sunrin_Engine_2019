#pragma once

#include "SR_Component.h"
#include "SR_DirtyFlagMath.h"

namespace SunrinEngine
{

	class SR_Transform : public SR_Component
	{
	public:
		explicit SR_Transform(SR_Entity * owner);

		virtual bool Update() override;

		void ResetTransform();

		void SetPosition(const SR_Vector3 & position) { m_localPosition.Set(position); }
		void SetPosition(float x, float y, float z) { m_localPosition.Set(x, y, z); }
		void SetPositionX(float x) { m_localPosition.SetX(x); }
		void SetPositionY(float y) { m_localPosition.SetY(y); }
		void SetPositionZ(float z) { m_localPosition.SetZ(z); }
		void SetRotation(const SR_Vector3 & rotation) { m_localRotation.Set(rotation); }
		void SetRotation(float x, float y, float z) { m_localRotation.Set(x, y, z); }
		void SetRotationX(float x) { m_localRotation.SetX(x); }
		void SetRotationY(float y) { m_localRotation.SetY(y); }
		void SetRotationZ(float z) { m_localRotation.SetZ(z); }
		void SetScale(const SR_Vector3 & scale) { m_localScale.Set(scale); }
		void SetScale(float x, float y, float z) { m_localScale.Set(x, y, z); }
		void SetScaleX(float x) { m_localScale.SetX(x); }
		void SetScaleY(float y) { m_localScale.SetY(y); }
		void SetScaleZ(float z) { m_localScale.SetZ(z); }

		void AddPosition(const SR_Vector3 & position) { m_localPosition.Add(position); }
		void AddPosition(float x, float y, float z) { m_localPosition.Add(x, y, z); }
		void AddPositionX(float x) { m_localPosition.AddX(x); }
		void AddPositionY(float y) { m_localPosition.AddY(y); }
		void AddPositionZ(float z) { m_localPosition.AddZ(z); }
		void AddRotation(const SR_Vector3 & rotation) { m_localRotation.Add(rotation); }
		void AddRotation(float x, float y, float z) { m_localRotation.Add(x, y, z); }
		void AddRotationX(float x) { m_localRotation.AddX(x); }
		void AddRotationY(float y) { m_localRotation.AddY(y); }
		void AddRotationZ(float z) { m_localRotation.AddZ(z); }
		void AddScale(const SR_Vector3 & scale) { m_localScale.Add(scale); }
		void AddScale(float x, float y, float z) { m_localScale.Add(x, y, z); }
		void AddScaleX(float x) { m_localScale.AddX(x); }
		void AddScaleY(float y) { m_localScale.AddY(y); }
		void AddScaleZ(float z) { m_localScale.AddZ(z); }

		const SR_Vector3 & GetLocalPosition() const noexcept { return m_localPosition.GetValue(); }
		const SR_Vector3 & GetLocalRotation() const noexcept { return m_localRotation.GetValue(); }
		const SR_Vector3 & GetLocalScale() const noexcept { return m_localScale.GetValue(); }
		const SR_Vector3 & GetWorldPosition() const noexcept { return m_worldPosition; }
		const SR_Vector3 & GetWorldRotation() const noexcept { return m_worldRotation; }
		const SR_Vector3 & GetWorldScale() const noexcept { return m_worldScale; }
		const SR_Matrix4x4& GetWorldMatrix() const noexcept { return m_worldMatrix; }
		const SR_Matrix4x4 & GetLocalMatrix() const noexcept { return m_localMatrix.GetValue(); }
		const SR_Matrix4x4 & GetParentMatrix() const noexcept { return m_parentMatrix.GetValue(); }
		const SR_Matrix4x4 * GetWorldMatrixAddressOf() const noexcept { return &m_worldMatrix; }
		const SR_Matrix4x4 * GetLocalMatrixAddressOf() const noexcept { return m_localMatrix.GetAddressOf(); }
		const SR_Matrix4x4 * GetParentMatrixAddressOf() const noexcept { return m_parentMatrix.GetAddressOf(); }

	private:
		SR_Vector3 m_worldPosition;
		SR_Vector3 m_worldRotation;
		SR_Vector3 m_worldScale;
		SR_Matrix4x4 m_worldMatrix;
		SR_DirtyFlagVector3 m_localPosition;
		SR_DirtyFlagVector3 m_localRotation;
		SR_DirtyFlagVector3 m_localScale;
		SR_DirtyFlagMatrix4x4 m_localMatrix;
		SR_DirtyFlagMatrix4x4 m_parentMatrix;

	};

}