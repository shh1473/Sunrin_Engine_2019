// =====================================================================
//  이 파일은 ODKEngine_beta_0_3의 소스코드입니다.
//  만든이 : 5DK
// =====================================================================

#pragma once

#include "OE_Component.h"
#include "OE_Math.h"
#include "OE_DirtyFlagMath.h"

namespace ODKE
{

	// 엔티티의 변형 상태를 설정하는 컴포넌트 클래스입니다.
	class OE_Transform : public OE_Component
	{
	public:
		explicit OE_Transform();

		// 현재 변형 상태를 기준으로 월드 매트릭스를 업데이트합니다.
		// 콜백 함수이므로 직접 호출하면 안 됩니다.
		virtual bool Update() override;

		// 변형 상태를 원점으로 초기화합니다.
		void ResetTransform();

		// 로컬 위치값 세 요소를 한 번에 설정합니다.
		void SetPosition(const OE_Float3& position) { m_localPosition.Set(position); }

		// 로컬 위치값 세 요소를 한 번에 설정합니다.
		void SetPosition(float x, float y, float z) { m_localPosition.Set(x, y, z); }

		// 로컬 위치의 X값을 설정합니다.
		void SetPositionX(float x) { m_localPosition.SetX(x); }

		// 로컬 위치의 Y값을 설정합니다.
		void SetPositionY(float y) { m_localPosition.SetY(y); }

		// 로컬 위치의 Z값을 설정합니다.
		void SetPositionZ(float z) { m_localPosition.SetZ(z); }

		// 로컬 회전값 세 요소를 한 번에 설정합니다.
		void SetRotation(const OE_Float3& rotation) { m_localRotation.Set(rotation); }

		// 로컬 회전값 세 요소를 한 번에 설정합니다.
		void SetRotation(float x, float y, float z) { m_localRotation.Set(x, y, z); }

		// 로컬 회전의 X값을 설정합니다.
		void SetRotationX(float x) { m_localRotation.SetX(x); }

		// 로컬 회전의 Y값을 설정합니다.
		void SetRotationY(float y) { m_localRotation.SetY(y); }

		// 로컬 회전의 Z값을 설정합니다.
		void SetRotationZ(float z) { m_localRotation.SetZ(z); }

		// 로컬 크기값 세 요소를 한 번에 설정합니다.
		void SetScale(const OE_Float3& scale) { m_localScale.Set(scale); }

		// 로컬 크기값 세 요소를 한 번에 설정합니다.
		void SetScale(float x, float y, float z) { m_localScale.Set(x, y, z); }

		// 로컬 크기의 X값을 설정합니다.
		void SetScaleX(float x) { m_localScale.SetX(x); }

		// 로컬 크기의 Y값을 설정합니다.
		void SetScaleY(float y) { m_localScale.SetY(y); }

		// 로컬 크기의 Z값을 설정합니다.
		void SetScaleZ(float z) { m_localScale.SetZ(z); }

		// 로컬 위치값 세 요소를 한 번에 더하여 설정합니다.
		void AddPosition(const OE_Float3& position) { m_localPosition.Add(position); }

		// 로컬 위치값 세 요소를 한 번에 더하여 설정합니다.
		void AddPosition(float x, float y, float z) { m_localPosition.Add(x, y, z); }

		// 로컬 위치의 X값을 기존 값에 더하여 설정합니다.
		void AddPositionX(float x) { m_localPosition.AddX(x); }

		// 로컬 위치의 Y값을 기존 값에 더하여 설정합니다.
		void AddPositionY(float y) { m_localPosition.AddY(y); }

		// 로컬 위치의 Z값을 기존 값에 더하여 설정합니다.
		void AddPositionZ(float z) { m_localPosition.AddZ(z); }

		// 로컬 회전값 세 요소를 한 번에 더하여 설정합니다.
		void AddRotation(const OE_Float3& rotation) { m_localRotation.Add(rotation); }

		// 로컬 회전값 세 요소를 한 번에 더하여 설정합니다.
		void AddRotation(float x, float y, float z) { m_localRotation.Add(x, y, z); }

		// 로컬 회전의 X값을 기존 값에 더하여 설정합니다.
		void AddRotationX(float x) { m_localRotation.AddX(x); }

		// 로컬 회전의 Y값을 기존 값에 더하여 설정합니다.
		void AddRotationY(float y) { m_localRotation.AddY(y); }

		// 로컬 회전의 Z값을 기존 값에 더하여 설정합니다.
		void AddRotationZ(float z) { m_localRotation.AddZ(z); }

		// 로컬 크기값 세 요소를 한 번에 더하여 설정합니다.
		void AddScale(const OE_Float3& scale) { m_localScale.Add(scale); }

		// 로컬 크기값 세 요소를 한 번에 더하여 설정합니다.
		void AddScale(float x, float y, float z) { m_localScale.Add(x, y, z); }

		// 로컬 크기의 X값을 기존 값에 더하여 설정합니다.
		void AddScaleX(float x) { m_localScale.AddX(x); }

		// 로컬 크기의 Y값을 기존 값에 더하여 설정합니다.
		void AddScaleY(float y) { m_localScale.AddY(y); }

		// 로컬 크기의 Z값을 기존 값에 더하여 설정합니다.
		void AddScaleZ(float z) { m_localScale.AddZ(z); }

		// 로컬 위치값 세 요소를 한 번에 가져옵니다.
		const OE_Float3& GetLocalPosition()const { return m_localPosition.GetValue(); }

		// 로컬 회전값 세 요소를 한 번에 가져옵니다.
		const OE_Float3& GetLocalRotation()const { return m_localRotation.GetValue(); }

		// 로컬 크기값 세 요소를 한 번에 가져옵니다.
		const OE_Float3& GetLocalScale()const { return m_localScale.GetValue(); }

		// 월드 위치값 세 요소를 한 번에 가져옵니다.
		const OE_Float3& GetWorldPosition()const { return m_worldPosition; }

		// 월드 회전값 세 요소를 한 번에 가져옵니다.
		const OE_Float3& GetWorldRotation()const { return m_worldRotation; }

		// 월드 크기값 세 요소를 한 번에 가져옵니다.
		const OE_Float3& GetWorldScale()const { return m_worldScale; }

		// 월드 매트릭스를 가져옵니다.
		const OE_Matrix4x4& GetWorldMatrix()const { return m_worldMatrix; }

		// 로컬 매트릭스를 가져옵니다.
		const OE_Matrix4x4& GetLocalMatrix()const { return m_localMatrix.GetValue(); }

		// 부모의 월드 매트릭스를 가져옵니다.
		const OE_Matrix4x4& GetParentMatrix()const { return m_parentMatrix.GetValue(); }

		// 월드 매트릭스의 주소를 가져옵니다.
		const OE_Matrix4x4* GetWorldMatrixAddressOf()const { return &m_worldMatrix; }

		// 로컬 매트릭스의 주소를 가져옵니다.
		const OE_Matrix4x4* GetLocalMatrixAddressOf()const { return m_localMatrix.GetAddressOf(); }

		// 부모의 월드 매트릭스의 주소를 가져옵니다.
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