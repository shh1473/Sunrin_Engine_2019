// =====================================================================
//  �� ������ ODKEngine_beta_0_3�� �ҽ��ڵ��Դϴ�.
//  ������ : 5DK
// =====================================================================

#pragma once

#include "OE_Component.h"
#include "OE_Math.h"
#include "OE_DirtyFlagMath.h"

namespace ODKE
{

	// ��ƼƼ�� ���� ���¸� �����ϴ� ������Ʈ Ŭ�����Դϴ�.
	class OE_Transform : public OE_Component
	{
	public:
		explicit OE_Transform();

		// ���� ���� ���¸� �������� ���� ��Ʈ������ ������Ʈ�մϴ�.
		// �ݹ� �Լ��̹Ƿ� ���� ȣ���ϸ� �� �˴ϴ�.
		virtual bool Update() override;

		// ���� ���¸� �������� �ʱ�ȭ�մϴ�.
		void ResetTransform();

		// ���� ��ġ�� �� ��Ҹ� �� ���� �����մϴ�.
		void SetPosition(const OE_Float3& position) { m_localPosition.Set(position); }

		// ���� ��ġ�� �� ��Ҹ� �� ���� �����մϴ�.
		void SetPosition(float x, float y, float z) { m_localPosition.Set(x, y, z); }

		// ���� ��ġ�� X���� �����մϴ�.
		void SetPositionX(float x) { m_localPosition.SetX(x); }

		// ���� ��ġ�� Y���� �����մϴ�.
		void SetPositionY(float y) { m_localPosition.SetY(y); }

		// ���� ��ġ�� Z���� �����մϴ�.
		void SetPositionZ(float z) { m_localPosition.SetZ(z); }

		// ���� ȸ���� �� ��Ҹ� �� ���� �����մϴ�.
		void SetRotation(const OE_Float3& rotation) { m_localRotation.Set(rotation); }

		// ���� ȸ���� �� ��Ҹ� �� ���� �����մϴ�.
		void SetRotation(float x, float y, float z) { m_localRotation.Set(x, y, z); }

		// ���� ȸ���� X���� �����մϴ�.
		void SetRotationX(float x) { m_localRotation.SetX(x); }

		// ���� ȸ���� Y���� �����մϴ�.
		void SetRotationY(float y) { m_localRotation.SetY(y); }

		// ���� ȸ���� Z���� �����մϴ�.
		void SetRotationZ(float z) { m_localRotation.SetZ(z); }

		// ���� ũ�Ⱚ �� ��Ҹ� �� ���� �����մϴ�.
		void SetScale(const OE_Float3& scale) { m_localScale.Set(scale); }

		// ���� ũ�Ⱚ �� ��Ҹ� �� ���� �����մϴ�.
		void SetScale(float x, float y, float z) { m_localScale.Set(x, y, z); }

		// ���� ũ���� X���� �����մϴ�.
		void SetScaleX(float x) { m_localScale.SetX(x); }

		// ���� ũ���� Y���� �����մϴ�.
		void SetScaleY(float y) { m_localScale.SetY(y); }

		// ���� ũ���� Z���� �����մϴ�.
		void SetScaleZ(float z) { m_localScale.SetZ(z); }

		// ���� ��ġ�� �� ��Ҹ� �� ���� ���Ͽ� �����մϴ�.
		void AddPosition(const OE_Float3& position) { m_localPosition.Add(position); }

		// ���� ��ġ�� �� ��Ҹ� �� ���� ���Ͽ� �����մϴ�.
		void AddPosition(float x, float y, float z) { m_localPosition.Add(x, y, z); }

		// ���� ��ġ�� X���� ���� ���� ���Ͽ� �����մϴ�.
		void AddPositionX(float x) { m_localPosition.AddX(x); }

		// ���� ��ġ�� Y���� ���� ���� ���Ͽ� �����մϴ�.
		void AddPositionY(float y) { m_localPosition.AddY(y); }

		// ���� ��ġ�� Z���� ���� ���� ���Ͽ� �����մϴ�.
		void AddPositionZ(float z) { m_localPosition.AddZ(z); }

		// ���� ȸ���� �� ��Ҹ� �� ���� ���Ͽ� �����մϴ�.
		void AddRotation(const OE_Float3& rotation) { m_localRotation.Add(rotation); }

		// ���� ȸ���� �� ��Ҹ� �� ���� ���Ͽ� �����մϴ�.
		void AddRotation(float x, float y, float z) { m_localRotation.Add(x, y, z); }

		// ���� ȸ���� X���� ���� ���� ���Ͽ� �����մϴ�.
		void AddRotationX(float x) { m_localRotation.AddX(x); }

		// ���� ȸ���� Y���� ���� ���� ���Ͽ� �����մϴ�.
		void AddRotationY(float y) { m_localRotation.AddY(y); }

		// ���� ȸ���� Z���� ���� ���� ���Ͽ� �����մϴ�.
		void AddRotationZ(float z) { m_localRotation.AddZ(z); }

		// ���� ũ�Ⱚ �� ��Ҹ� �� ���� ���Ͽ� �����մϴ�.
		void AddScale(const OE_Float3& scale) { m_localScale.Add(scale); }

		// ���� ũ�Ⱚ �� ��Ҹ� �� ���� ���Ͽ� �����մϴ�.
		void AddScale(float x, float y, float z) { m_localScale.Add(x, y, z); }

		// ���� ũ���� X���� ���� ���� ���Ͽ� �����մϴ�.
		void AddScaleX(float x) { m_localScale.AddX(x); }

		// ���� ũ���� Y���� ���� ���� ���Ͽ� �����մϴ�.
		void AddScaleY(float y) { m_localScale.AddY(y); }

		// ���� ũ���� Z���� ���� ���� ���Ͽ� �����մϴ�.
		void AddScaleZ(float z) { m_localScale.AddZ(z); }

		// ���� ��ġ�� �� ��Ҹ� �� ���� �����ɴϴ�.
		const OE_Float3& GetLocalPosition()const { return m_localPosition.GetValue(); }

		// ���� ȸ���� �� ��Ҹ� �� ���� �����ɴϴ�.
		const OE_Float3& GetLocalRotation()const { return m_localRotation.GetValue(); }

		// ���� ũ�Ⱚ �� ��Ҹ� �� ���� �����ɴϴ�.
		const OE_Float3& GetLocalScale()const { return m_localScale.GetValue(); }

		// ���� ��ġ�� �� ��Ҹ� �� ���� �����ɴϴ�.
		const OE_Float3& GetWorldPosition()const { return m_worldPosition; }

		// ���� ȸ���� �� ��Ҹ� �� ���� �����ɴϴ�.
		const OE_Float3& GetWorldRotation()const { return m_worldRotation; }

		// ���� ũ�Ⱚ �� ��Ҹ� �� ���� �����ɴϴ�.
		const OE_Float3& GetWorldScale()const { return m_worldScale; }

		// ���� ��Ʈ������ �����ɴϴ�.
		const OE_Matrix4x4& GetWorldMatrix()const { return m_worldMatrix; }

		// ���� ��Ʈ������ �����ɴϴ�.
		const OE_Matrix4x4& GetLocalMatrix()const { return m_localMatrix.GetValue(); }

		// �θ��� ���� ��Ʈ������ �����ɴϴ�.
		const OE_Matrix4x4& GetParentMatrix()const { return m_parentMatrix.GetValue(); }

		// ���� ��Ʈ������ �ּҸ� �����ɴϴ�.
		const OE_Matrix4x4* GetWorldMatrixAddressOf()const { return &m_worldMatrix; }

		// ���� ��Ʈ������ �ּҸ� �����ɴϴ�.
		const OE_Matrix4x4* GetLocalMatrixAddressOf()const { return m_localMatrix.GetAddressOf(); }

		// �θ��� ���� ��Ʈ������ �ּҸ� �����ɴϴ�.
		const OE_Matrix4x4* GetParentMatrixAddressOf()const { return m_parentMatrix.GetAddressOf(); }

	private:
		OE_Float3 m_worldPosition;
		OE_Float3 m_worldRotation;
		OE_Float3 m_worldScale;
		OE_Matrix4x4 m_worldMatrix;
		OE_DirtyFlagFloat3 m_localPosition;
		OE_DirtyFlagFloat3 m_localRotation;
		OE_DirtyFlagFloat3 m_localScale;
		OE_DirtyFlagMatrix4x4 m_localMatrix;
		OE_DirtyFlagMatrix4x4 m_parentMatrix;

	};

}