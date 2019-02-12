#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Math
	{
	public:
		static float PI() { return M_PI; }
		static float DegToRad() { return M_DegToRad; }
		static float RadToDeg() { return M_RadToDeg; }
		static float Sin(float value) { return sinf(value); }
		static float Cos(float value) { return cosf(value); }
		static float Tan(float value) { return tanf(value); }
		static float ASin(float value) { return asinf(value); }
		static float ACos(float value) { return acosf(value); }
		static float ATan1(float value) { return atanf(value); }
		static float ATan2(float x, float y) { return atan2f(x, y); }

	private:
		explicit SR_Math() noexcept;

	private:
		static const float M_PI;
		static const float M_DegToRad;
		static const float M_RadToDeg;

	};

}