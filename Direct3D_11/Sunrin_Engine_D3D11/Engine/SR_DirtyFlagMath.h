#pragma once

#include "SR_Vector2.h"
#include "SR_Vector3.h"
#include "SR_Vector4.h"
#include "SR_Matrix3x2.h"
#include "SR_Matrix4x4.h"
#include "SR_DirtyFlag.h"

namespace SunrinEngine
{

	class SR_DirtyFlagVector1 : public SR_DirtyFlag<float>
	{
	public:
		explicit SR_DirtyFlagVector1();

		void Set(float f) { m_curValue = f; }
		void Add(float f) { m_curValue += f; }

	};

	class SR_DirtyFlagVector2 : public SR_DirtyFlag<SR_Vector2>
	{
	public:
		explicit SR_DirtyFlagVector2();

		void Set(const SR_Vector2 & vector2) { m_curValue = vector2; }
		void Set(float x, float y) { m_curValue.m_x = x; m_curValue.m_y = y; }
		void SetX(float x) { m_curValue.m_x = x; }
		void SetY(float y) { m_curValue.m_y = y; }
		void Add(const SR_Vector2 & vector2) { m_curValue += vector2; }
		void Add(float x, float y) { m_curValue.m_x += x; m_curValue.m_y += y; }
		void AddX(float x) { m_curValue.m_x += x; }
		void AddY(float y) { m_curValue.m_y += y; }

	};

	class SR_DirtyFlagVector3 : public SR_DirtyFlag<SR_Vector3>
	{
	public:
		explicit SR_DirtyFlagVector3();

		void Set(const SR_Vector3 & vector3) { m_curValue = vector3; }
		void Set(float x, float y, float z) { m_curValue.m_x = x; m_curValue.m_y = y; m_curValue.m_z = z; }
		void SetX(float x) { m_curValue.m_x = x; }
		void SetY(float y) { m_curValue.m_y = y; }
		void SetZ(float z) { m_curValue.m_z = z; }
		void Add(const SR_Vector3 & vector3) { m_curValue += vector3; }
		void Add(float x, float y, float z) { m_curValue.m_x += x; m_curValue.m_y += y; m_curValue.m_z += z; }
		void AddX(float x) { m_curValue.m_x += x; }
		void AddY(float y) { m_curValue.m_y += y; }
		void AddZ(float z) { m_curValue.m_z += z; }

	};

	class SR_DirtyFlagVector4 : public SR_DirtyFlag<SR_Vector4>
	{
	public:
		explicit SR_DirtyFlagVector4();

		void Set(const SR_Vector4 & vector4) { m_curValue = vector4; }
		void Set(float x, float y, float z, float w) { m_curValue.m_x = x; m_curValue.m_y = y; m_curValue.m_z = z; m_curValue.m_w = w; }
		void SetX(float x) { m_curValue.m_x = x; }
		void SetY(float y) { m_curValue.m_y = y; }
		void SetZ(float z) { m_curValue.m_z = z; }
		void SetW(float w) { m_curValue.m_w = w; }
		void Add(const SR_Vector4 & vector4) { m_curValue += vector4; }
		void Add(float x, float y, float z, float w) { m_curValue.m_x += x; m_curValue.m_y += y; m_curValue.m_z += z; m_curValue.m_w += w; }
		void AddX(float x) { m_curValue.m_x += x; }
		void AddY(float y) { m_curValue.m_y += y; }
		void AddZ(float z) { m_curValue.m_z += z; }
		void AddW(float w) { m_curValue.m_w += w; }

	};

	class SR_DirtyFlagMatrix3x2 : public SR_DirtyFlag<SR_Matrix3x2>
	{
	public:
		explicit SR_DirtyFlagMatrix3x2();

		void Multiply(const SR_Matrix3x2 & matrix3x2) { m_curValue *= matrix3x2; }

		void Set(const SR_Matrix3x2 & matrix3x2) { m_curValue = matrix3x2; }

	};

	class SR_DirtyFlagMatrix4x4 : public SR_DirtyFlag<SR_Matrix4x4>
	{
	public:
		explicit SR_DirtyFlagMatrix4x4();

		void Multiply(const SR_Matrix4x4 & matrix4x4) { m_curValue *= matrix4x4; }

		void Set(const SR_Matrix4x4 & matrix4x4) { m_curValue = matrix4x4; }

	};

}