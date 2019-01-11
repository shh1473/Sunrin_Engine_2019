#include "SR_PCH.h"
#include "SR_Matrix3x2.h"

namespace SunrinEngine
{

	const SR_Matrix3x2 SR_Matrix3x2::M_Identity{
		1.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 0.0f };

	SR_Matrix3x2::SR_Matrix3x2() noexcept :
		m_float3x2{
		1.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 0.0f }
	{

	}

	SR_Matrix3x2::SR_Matrix3x2(
		float m11, float m12,
		float m21, float m22,
		float m31, float m32) noexcept :
		m_float3x2{
		m11, m12,
		m21, m22,
		m31, m32 }
	{

	}

	SR_Matrix3x2::SR_Matrix3x2(
		DirectX::XMFLOAT2 r1,
		DirectX::XMFLOAT2 r2,
		DirectX::XMFLOAT2 r3) noexcept :
		m_float3x2{
		r1.x, r1.y,
		r2.x, r2.y,
		r3.x, r3.y }
	{

	}

	SR_Matrix3x2::SR_Matrix3x2(const SR_Matrix3x2 & matrix3x2) noexcept :
		m_float3x2{ matrix3x2.m_float3x2 }
	{

	}

	SR_Matrix3x2::SR_Matrix3x2(SR_Matrix3x2 && matrix3x2) noexcept :
		m_float3x2{ std::move(matrix3x2.m_float3x2) }
	{

	}

	SR_Matrix3x2::SR_Matrix3x2(const D2D1::Matrix3x2F & float3x2) noexcept :
		m_float3x2{ float3x2 }
	{

	}

	SR_Matrix3x2::SR_Matrix3x2(D2D1::Matrix3x2F && float3x2) noexcept :
		m_float3x2{ std::move(float3x2) }
	{

	}

	SR_Matrix3x2::~SR_Matrix3x2() noexcept
	{

	}

	bool SR_Matrix3x2::operator==(const SR_Matrix3x2 & matrix3x2) const noexcept
	{
		return
			(m_float3x2._11 == matrix3x2.m_float3x2._12) &&
			(m_float3x2._21 == matrix3x2.m_float3x2._22) &&
			(m_float3x2._31 == matrix3x2.m_float3x2._32);
	}

	bool SR_Matrix3x2::operator!=(const SR_Matrix3x2 & matrix3x2) const noexcept
	{
		return
			(m_float3x2._11 != matrix3x2.m_float3x2._12) ||
			(m_float3x2._21 != matrix3x2.m_float3x2._22) ||
			(m_float3x2._31 != matrix3x2.m_float3x2._32);
	}

	SR_Matrix3x2 & SR_Matrix3x2::operator=(const SR_Matrix3x2 & matrix3x2) noexcept
	{
		m_float3x2 = matrix3x2.m_float3x2;

		return *this;
	}

	SR_Matrix3x2 & SR_Matrix3x2::operator=(SR_Matrix3x2 && matrix3x2) noexcept
	{
		m_float3x2 = std::move(matrix3x2.m_float3x2);

		return *this;
	}

	SR_Matrix3x2 & SR_Matrix3x2::operator+=(const SR_Matrix3x2 & matrix3x2) noexcept
	{
		m_float3x2._11 += matrix3x2.m_float3x2._11; m_float3x2._12 += matrix3x2.m_float3x2._12;
		m_float3x2._21 += matrix3x2.m_float3x2._21; m_float3x2._22 += matrix3x2.m_float3x2._22;
		m_float3x2._31 += matrix3x2.m_float3x2._31; m_float3x2._32 += matrix3x2.m_float3x2._32;

		return *this;
	}

	SR_Matrix3x2 & SR_Matrix3x2::operator+=(float scalar) noexcept
	{
		m_float3x2._11 += scalar; m_float3x2._12 += scalar;
		m_float3x2._21 += scalar; m_float3x2._22 += scalar;
		m_float3x2._31 += scalar; m_float3x2._32 += scalar;

		return *this;
	}

	SR_Matrix3x2 & SR_Matrix3x2::operator-=(const SR_Matrix3x2 & matrix3x2) noexcept
	{
		m_float3x2._11 -= matrix3x2.m_float3x2._11; m_float3x2._12 -= matrix3x2.m_float3x2._12;
		m_float3x2._21 -= matrix3x2.m_float3x2._21; m_float3x2._22 -= matrix3x2.m_float3x2._22;
		m_float3x2._31 -= matrix3x2.m_float3x2._31; m_float3x2._32 -= matrix3x2.m_float3x2._32;

		return *this;
	}

	SR_Matrix3x2 & SR_Matrix3x2::operator-=(float scalar) noexcept
	{
		m_float3x2._11 -= scalar; m_float3x2._12 -= scalar;
		m_float3x2._21 -= scalar; m_float3x2._22 -= scalar;
		m_float3x2._31 -= scalar; m_float3x2._32 -= scalar;

		return *this;
	}

	SR_Matrix3x2 & SR_Matrix3x2::operator*=(const SR_Matrix3x2 & matrix3x2) noexcept
	{
		m_float3x2.SetProduct(m_float3x2, matrix3x2.m_float3x2);

		return *this;
	}

	SR_Matrix3x2 & SR_Matrix3x2::operator*=(float scalar) noexcept
	{
		m_float3x2._11 *= scalar; m_float3x2._12 *= scalar;
		m_float3x2._21 *= scalar; m_float3x2._22 *= scalar;
		m_float3x2._31 *= scalar; m_float3x2._32 *= scalar;

		return *this;
	}

	SR_Matrix3x2 & SR_Matrix3x2::operator/=(const SR_Matrix3x2 & matrix3x2) noexcept
	{
		m_float3x2._11 /= matrix3x2.m_float3x2._11; m_float3x2._12 /= matrix3x2.m_float3x2._12;
		m_float3x2._21 /= matrix3x2.m_float3x2._21; m_float3x2._22 /= matrix3x2.m_float3x2._22;
		m_float3x2._31 /= matrix3x2.m_float3x2._31; m_float3x2._32 /= matrix3x2.m_float3x2._32;

		return *this;
	}

	SR_Matrix3x2 & SR_Matrix3x2::operator/=(float scalar) noexcept
	{
		m_float3x2._11 /= scalar; m_float3x2._12 /= scalar;
		m_float3x2._21 /= scalar; m_float3x2._22 /= scalar;
		m_float3x2._31 /= scalar; m_float3x2._32 /= scalar;

		return *this;
	}

	const SR_Matrix3x2 SR_Matrix3x2::operator-() const noexcept
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2._11 = -m_float3x2._11; mat3x2.m_float3x2._12 = -m_float3x2._12;
		mat3x2.m_float3x2._21 = -m_float3x2._21; mat3x2.m_float3x2._22 = -m_float3x2._22;
		mat3x2.m_float3x2._31 = -m_float3x2._31; mat3x2.m_float3x2._32 = -m_float3x2._32;

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::operator+(const SR_Matrix3x2 & matrix3x2) noexcept
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2._11 = m_float3x2._11 + matrix3x2.m_float3x2._11; mat3x2.m_float3x2._12 = m_float3x2._12 + matrix3x2.m_float3x2._12;
		mat3x2.m_float3x2._21 = m_float3x2._21 + matrix3x2.m_float3x2._21; mat3x2.m_float3x2._22 = m_float3x2._22 + matrix3x2.m_float3x2._22;
		mat3x2.m_float3x2._31 = m_float3x2._31 + matrix3x2.m_float3x2._31; mat3x2.m_float3x2._32 = m_float3x2._32 + matrix3x2.m_float3x2._32;

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::operator+(float scalar) noexcept
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2._11 = m_float3x2._11 + scalar; mat3x2.m_float3x2._12 = m_float3x2._12 + scalar;
		mat3x2.m_float3x2._21 = m_float3x2._21 + scalar; mat3x2.m_float3x2._22 = m_float3x2._22 + scalar;
		mat3x2.m_float3x2._31 = m_float3x2._31 + scalar; mat3x2.m_float3x2._32 = m_float3x2._32 + scalar;

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::operator-(const SR_Matrix3x2 & matrix3x2) noexcept
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2._11 = m_float3x2._11 - matrix3x2.m_float3x2._11; mat3x2.m_float3x2._12 = m_float3x2._12 - matrix3x2.m_float3x2._12;
		mat3x2.m_float3x2._21 = m_float3x2._21 - matrix3x2.m_float3x2._21; mat3x2.m_float3x2._22 = m_float3x2._22 - matrix3x2.m_float3x2._22;
		mat3x2.m_float3x2._31 = m_float3x2._31 - matrix3x2.m_float3x2._31; mat3x2.m_float3x2._32 = m_float3x2._32 - matrix3x2.m_float3x2._32;

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::operator-(float scalar) noexcept
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2._11 = m_float3x2._11 - scalar; mat3x2.m_float3x2._12 = m_float3x2._12 - scalar;
		mat3x2.m_float3x2._21 = m_float3x2._21 - scalar; mat3x2.m_float3x2._22 = m_float3x2._22 - scalar;
		mat3x2.m_float3x2._31 = m_float3x2._31 - scalar; mat3x2.m_float3x2._32 = m_float3x2._32 - scalar;

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::operator*(const SR_Matrix3x2 & matrix3x2) noexcept
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2.SetProduct(m_float3x2, matrix3x2.m_float3x2);

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::operator*(float scalar) noexcept
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2._11 = m_float3x2._11 * scalar; mat3x2.m_float3x2._12 = m_float3x2._12 * scalar;
		mat3x2.m_float3x2._21 = m_float3x2._21 * scalar; mat3x2.m_float3x2._22 = m_float3x2._22 * scalar;
		mat3x2.m_float3x2._31 = m_float3x2._31 * scalar; mat3x2.m_float3x2._32 = m_float3x2._32 * scalar;

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::operator/(const SR_Matrix3x2 & matrix3x2) noexcept
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2._11 = m_float3x2._11 / matrix3x2.m_float3x2._11; mat3x2.m_float3x2._12 = m_float3x2._12 / matrix3x2.m_float3x2._12;
		mat3x2.m_float3x2._21 = m_float3x2._21 / matrix3x2.m_float3x2._21; mat3x2.m_float3x2._22 = m_float3x2._22 / matrix3x2.m_float3x2._22;
		mat3x2.m_float3x2._31 = m_float3x2._31 / matrix3x2.m_float3x2._31; mat3x2.m_float3x2._32 = m_float3x2._32 / matrix3x2.m_float3x2._32;

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::operator/(float scalar) noexcept
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2._11 = m_float3x2._11 / scalar; mat3x2.m_float3x2._12 = m_float3x2._12 / scalar;
		mat3x2.m_float3x2._21 = m_float3x2._21 / scalar; mat3x2.m_float3x2._22 = m_float3x2._22 / scalar;
		mat3x2.m_float3x2._31 = m_float3x2._31 / scalar; mat3x2.m_float3x2._32 = m_float3x2._32 / scalar;

		return std::move(mat3x2);
	}

	void SR_Matrix3x2::Inverse()
	{
		m_float3x2.Invert();
	}

	float SR_Matrix3x2::GetDeterminant() const
	{
		return m_float3x2.Determinant();
	}

	const SR_Matrix3x2 SR_Matrix3x2::GetInverse() const
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2 = m_float3x2;
		mat3x2.m_float3x2.Invert();

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::CreateTranslationMatrix(float x, float y)
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2._31 = x;
		mat3x2.m_float3x2._32 = y;

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::CreateRotationMatrix(float angle, float centerX, float centerY)
	{
		D2D1_POINT_2F center{ centerX, centerY };

		SR_Matrix3x2 mat3x2;

		D2D1MakeRotateMatrix(angle, std::move(center), &mat3x2.m_float3x2);

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::CreateScaleMatrix(float x, float y, float centerX, float centerY)
	{
		SR_Matrix3x2 mat3x2;

		mat3x2.m_float3x2._11 = x;
		mat3x2.m_float3x2._22 = y;
		mat3x2.m_float3x2._31 = centerX - x * centerX;
		mat3x2.m_float3x2._32 = centerY - y * centerY;

		return std::move(mat3x2);
	}

	const SR_Matrix3x2 SR_Matrix3x2::CreateSkewMatrix(float x, float y, float centerX, float centerY)
	{
		D2D1_POINT_2F center{ centerX, centerY };

		SR_Matrix3x2 mat3x2;

		D2D1MakeSkewMatrix(x, y, std::move(center), &mat3x2.m_float3x2);

		return std::move(mat3x2);
	}

}