#include "SR_PCH.h"

#include "SR_Matrix5x4.h"

namespace SunrinEngine
{

	const SR_Matrix5x4 SR_Matrix5x4::m_IDENTITY{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 0.0f };

	SR_Matrix5x4::SR_Matrix5x4() noexcept :
		m_float5x4{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 0.0f }
	{

	}

	SR_Matrix5x4::SR_Matrix5x4(
		float m_11, float m_12, float m_13, float m_14,
		float m_21, float m_22, float m_23, float m_24,
		float m_31, float m_32, float m_33, float m_34,
		float m_41, float m_42, float m_43, float m_44,
		float m_51, float m_52, float m_53, float m_54) noexcept :
		m_float5x4{
		m_11, m_12, m_13, m_14,
		m_21, m_22, m_23, m_24,
		m_31, m_32, m_33, m_34,
		m_41, m_42, m_43, m_44,
		m_51, m_52, m_53, m_54 }
	{

	}

	SR_Matrix5x4::SR_Matrix5x4(
		D2D1_VECTOR_4F r1,
		D2D1_VECTOR_4F r2,
		D2D1_VECTOR_4F r3,
		D2D1_VECTOR_4F r4,
		D2D1_VECTOR_4F r5) noexcept :
		m_float5x4{
		r1.x, r1.y, r1.z, r1.w,
		r2.x, r2.y, r2.z, r2.w,
		r3.x, r3.y, r3.z, r3.w,
		r4.x, r4.y, r4.z, r4.w,
		r5.x, r5.y, r5.z, r5.w }
	{

	}

	SR_Matrix5x4::SR_Matrix5x4(const SR_Matrix5x4 & matrix5x4) noexcept :
		m_float5x4{ matrix5x4.m_float5x4 }
	{

	}

	SR_Matrix5x4::SR_Matrix5x4(SR_Matrix5x4 && matrix5x4) noexcept :
		m_float5x4{ std::move(matrix5x4.m_float5x4) }
	{

	}

	SR_Matrix5x4::SR_Matrix5x4(const D2D1::Matrix5x4F & float5x4) noexcept :
		m_float5x4{ float5x4 }
	{

	}

	SR_Matrix5x4::SR_Matrix5x4(D2D1::Matrix5x4F && float5x4) noexcept :
		m_float5x4{ std::move(float5x4) }
	{

	}

	bool SR_Matrix5x4::operator==(const SR_Matrix5x4 & matrix5x4) const noexcept
	{
		return
			(m_float5x4._11 == matrix5x4.m_float5x4._11) && (m_float5x4._12 == matrix5x4.m_float5x4._12) && (m_float5x4._13 == matrix5x4.m_float5x4._13) && (m_float5x4._14 == matrix5x4.m_float5x4._14) &&
			(m_float5x4._21 == matrix5x4.m_float5x4._21) && (m_float5x4._22 == matrix5x4.m_float5x4._22) && (m_float5x4._23 == matrix5x4.m_float5x4._23) && (m_float5x4._24 == matrix5x4.m_float5x4._24) &&
			(m_float5x4._31 == matrix5x4.m_float5x4._31) && (m_float5x4._32 == matrix5x4.m_float5x4._32) && (m_float5x4._33 == matrix5x4.m_float5x4._33) && (m_float5x4._34 == matrix5x4.m_float5x4._34) &&
			(m_float5x4._41 == matrix5x4.m_float5x4._41) && (m_float5x4._42 == matrix5x4.m_float5x4._42) && (m_float5x4._43 == matrix5x4.m_float5x4._43) && (m_float5x4._44 == matrix5x4.m_float5x4._44) &&
			(m_float5x4._51 == matrix5x4.m_float5x4._51) && (m_float5x4._52 == matrix5x4.m_float5x4._52) && (m_float5x4._53 == matrix5x4.m_float5x4._53) && (m_float5x4._54 == matrix5x4.m_float5x4._54);
	}

	bool SR_Matrix5x4::operator!=(const SR_Matrix5x4 & matrix5x4) const noexcept
	{
		return
			(m_float5x4._11 != matrix5x4.m_float5x4._11) || (m_float5x4._12 != matrix5x4.m_float5x4._12) || (m_float5x4._13 != matrix5x4.m_float5x4._13) || (m_float5x4._14 != matrix5x4.m_float5x4._14) ||
			(m_float5x4._21 != matrix5x4.m_float5x4._21) || (m_float5x4._22 != matrix5x4.m_float5x4._22) || (m_float5x4._23 != matrix5x4.m_float5x4._23) || (m_float5x4._24 != matrix5x4.m_float5x4._24) ||
			(m_float5x4._31 != matrix5x4.m_float5x4._31) || (m_float5x4._32 != matrix5x4.m_float5x4._32) || (m_float5x4._33 != matrix5x4.m_float5x4._33) || (m_float5x4._34 != matrix5x4.m_float5x4._34) ||
			(m_float5x4._41 != matrix5x4.m_float5x4._41) || (m_float5x4._42 != matrix5x4.m_float5x4._42) || (m_float5x4._43 != matrix5x4.m_float5x4._43) || (m_float5x4._44 != matrix5x4.m_float5x4._44) ||
			(m_float5x4._51 != matrix5x4.m_float5x4._51) || (m_float5x4._52 != matrix5x4.m_float5x4._52) || (m_float5x4._53 != matrix5x4.m_float5x4._53) || (m_float5x4._54 != matrix5x4.m_float5x4._54);
	}

	SR_Matrix5x4 & SR_Matrix5x4::operator=(const SR_Matrix5x4 & matrix5x4) noexcept
	{
		m_float5x4 = matrix5x4.m_float5x4;

		return *this;
	}

	SR_Matrix5x4 & SR_Matrix5x4::operator=(SR_Matrix5x4 && matrix5x4) noexcept
	{
		m_float5x4 = std::move(matrix5x4.m_float5x4);

		return *this;
	}

}