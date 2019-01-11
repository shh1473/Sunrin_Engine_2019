#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Matrix4x4
	{

		constexpr explicit SR_Matrix4x4() noexcept;
		constexpr explicit SR_Matrix4x4(
			float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44) noexcept;
		constexpr explicit SR_Matrix4x4(
			const DirectX::XMFLOAT4 & r1,
			const DirectX::XMFLOAT4 & r2,
			const DirectX::XMFLOAT4 & r3,
			const DirectX::XMFLOAT4 & r4) noexcept;

		constexpr SR_Matrix4x4(const SR_Matrix4x4 & matrix4x4) noexcept;
		constexpr SR_Matrix4x4(SR_Matrix4x4 && matrix4x4) noexcept;
		constexpr SR_Matrix4x4(const DirectX::XMFLOAT4X4 & float4x4) noexcept;
		constexpr SR_Matrix4x4(DirectX::XMFLOAT4X4 && float4x4) noexcept;

		~SR_Matrix4x4() noexcept;

		bool operator==(const SR_Matrix4x4 & matrix4x4) const;
		bool operator!=(const SR_Matrix4x4 & matrix4x4) const;

		SR_Matrix4x4 & operator=(const SR_Matrix4x4 & matrix4x4) noexcept;
		SR_Matrix4x4 & operator=(SR_Matrix4x4 && matrix4x4) noexcept;
		SR_Matrix4x4 & operator+=(const SR_Matrix4x4 & matrix4x4);
		SR_Matrix4x4 & operator+=(float scalar);
		SR_Matrix4x4 & operator-=(const SR_Matrix4x4 & matrix4x4);
		SR_Matrix4x4 & operator-=(float scalar);
		SR_Matrix4x4 & operator*=(const SR_Matrix4x4 & matrix4x4);
		SR_Matrix4x4 & operator*=(float scalar);
		SR_Matrix4x4 & operator/=(const SR_Matrix4x4 & matrix4x4);
		SR_Matrix4x4 & operator/=(float scalar);

		const SR_Matrix4x4 operator-() const noexcept;
		const SR_Matrix4x4 operator+(const SR_Matrix4x4 & matrix4x4);
		const SR_Matrix4x4 operator+(float scalar);
		const SR_Matrix4x4 operator-(const SR_Matrix4x4 & matrix4x4);
		const SR_Matrix4x4 operator-(float scalar);
		const SR_Matrix4x4 operator*(const SR_Matrix4x4 & matrix4x4);
		const SR_Matrix4x4 operator*(float scalar);
		const SR_Matrix4x4 operator/(const SR_Matrix4x4 & matrix4x4);
		const SR_Matrix4x4 operator/(float scalar);

		bool Decompose(
			DirectX::XMFLOAT3 * translation,
			DirectX::XMFLOAT4 * rotation,
			DirectX::XMFLOAT3 * scale);

		void Transpose();

		void Inverse();

		float GetDeterminant() const;

		const SR_Matrix4x4 GetInverse() const;

		const SR_Matrix4x4 GetTranspose() const;

		void SetUpVector(const DirectX::XMFLOAT3 & float3) noexcept;
		void SetDownVector(const DirectX::XMFLOAT3 & float3) noexcept;
		void SetRightVector(const DirectX::XMFLOAT3 & float3) noexcept;
		void SetLeftVector(const DirectX::XMFLOAT3 & float3) noexcept;
		void SetForwardVector(const DirectX::XMFLOAT3 & float3) noexcept;
		void SetBackwardVector(const DirectX::XMFLOAT3 & float3) noexcept;
		void SetTranslation(const DirectX::XMFLOAT3 & float3) noexcept;

		const DirectX::XMFLOAT3 GetUpVector() const noexcept;
		const DirectX::XMFLOAT3 GetDownVector() const noexcept;
		const DirectX::XMFLOAT3 GetRightVector() const noexcept;
		const DirectX::XMFLOAT3 GetLeftVector() const noexcept;
		const DirectX::XMFLOAT3 GetForwardVector() const noexcept;
		const DirectX::XMFLOAT3 GetBackwardVector() const noexcept;
		const DirectX::XMFLOAT3 GetTranslation() const noexcept;

	public:
		static const SR_Matrix4x4 CreateBillboardMatrix(
			const DirectX::XMFLOAT3 & objectPosition,
			const DirectX::XMFLOAT3 & cameraPosition,
			const DirectX::XMFLOAT3 & cameraUpVector,
			const DirectX::XMFLOAT3 * cameraForwardVector = nullptr);

		static const SR_Matrix4x4 CreateConstrainedBillboardMatrix(
			const DirectX::XMFLOAT3 & objectPosition,
			const DirectX::XMFLOAT3 & cameraPosition,
			const DirectX::XMFLOAT3 & rotateAxis,
			const DirectX::XMFLOAT3 * cameraForwardVector = nullptr,
			const DirectX::XMFLOAT3 * objectForwardVector = nullptr);

		static const SR_Matrix4x4 CreateTranslationMatrix(const DirectX::XMFLOAT3 & position);

		static const SR_Matrix4x4 CreateRotationMatrix(const DirectX::XMFLOAT3 & rotation);

		static const SR_Matrix4x4 CreateScaleMatrix(const DirectX::XMFLOAT3 & scale);

		static const SR_Matrix4x4 CreatePerspectiveFieldOfView(float fieldOfView, float aspectRatio, float nearZ, float farZ);

		static const SR_Matrix4x4 CreatePerspective(float width, float height, float nearZ, float farZ);

		static const SR_Matrix4x4 CreatePerspectiveOffCenter(float left, float top, float right, float bottom, float nearZ, float farZ);

		static const SR_Matrix4x4 CreateOrthographic(float width, float height, float nearZ, float farZ);

		static const SR_Matrix4x4 CreateOrthographicOffCenter(float left, float top, float right, float bottom, float nearZ, float farZ);

		static const SR_Matrix4x4 CreateLookAt(const DirectX::XMFLOAT3 & eyeVector, const DirectX::XMFLOAT3 & lookVector, const DirectX::XMFLOAT3 & upVector);

		static const SR_Matrix4x4 CreateWorld(const DirectX::XMFLOAT3 & position, const DirectX::XMFLOAT3 & forwardVector, const DirectX::XMFLOAT3 & upVector);

		static const SR_Matrix4x4 Lerp(const SR_Matrix4x4 & matrix1, const SR_Matrix4x4 & matrix2, float t);

		static const SR_Matrix4x4 Transform(const SR_Matrix4x4 & matrix, const DirectX::XMFLOAT4 & quaternion);

		public:
			static const SR_Matrix4x4 M_Identity;

			union
			{
				struct
				{
					float m_11, m_12, m_13, m_14;
					float m_21, m_22, m_23, m_24;
					float m_31, m_32, m_33, m_34;
					float m_41, m_42, m_43, m_44;

				};

				DirectX::XMFLOAT4X4 m_float4x4;

			};

	};

}