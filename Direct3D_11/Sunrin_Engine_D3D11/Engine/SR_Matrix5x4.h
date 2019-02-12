#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Matrix5x4
	{
	public:
		explicit SR_Matrix5x4() noexcept;
		explicit SR_Matrix5x4(
			float m_11, float m_12, float m_13, float m_14,
			float m_21, float m_22, float m_23, float m_24,
			float m_31, float m_32, float m_33, float m_34,
			float m_41, float m_42, float m_43, float m_44,
			float m_51, float m_52, float m_53, float m_54) noexcept;
		explicit SR_Matrix5x4(
			D2D1_VECTOR_4F r1,
			D2D1_VECTOR_4F r2,
			D2D1_VECTOR_4F r3,
			D2D1_VECTOR_4F r4,
			D2D1_VECTOR_4F r5) noexcept;

		SR_Matrix5x4(const SR_Matrix5x4 & matrix5x4) noexcept;
		SR_Matrix5x4(SR_Matrix5x4 && matrix5x4) noexcept;
		SR_Matrix5x4(const D2D1::Matrix5x4F & float5x4) noexcept;
		SR_Matrix5x4(D2D1::Matrix5x4F && float5x4) noexcept;

		bool operator==(const SR_Matrix5x4 & matrix3x2) const noexcept;
		bool operator!=(const SR_Matrix5x4 & matrix3x2) const noexcept;

		SR_Matrix5x4 & operator=(const SR_Matrix5x4 & matrix3x2) noexcept;
		SR_Matrix5x4 & operator=(SR_Matrix5x4 && matrix3x2) noexcept;

	public:
		static const SR_Matrix5x4 m_IDENTITY;

		union
		{
			struct
			{
				float m_11, m_12, m_13, m_14;
				float m_21, m_22, m_23, m_24;
				float m_31, m_32, m_33, m_34;
				float m_41, m_42, m_43, m_44;
				float m_51, m_52, m_53, m_54;

			};

			float m_array[5][4];

			D2D1::Matrix5x4F m_float5x4;

		};

	};

}