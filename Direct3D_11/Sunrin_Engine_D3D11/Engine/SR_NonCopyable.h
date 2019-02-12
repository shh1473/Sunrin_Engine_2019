#pragma once

namespace SunrinEngine
{

	class SR_NonCopyable
	{
	public:
		explicit SR_NonCopyable() = default;
		virtual ~SR_NonCopyable() = default;

		explicit SR_NonCopyable(const SR_NonCopyable & copy) = delete;
		SR_NonCopyable& operator=(const SR_NonCopyable & copy) = delete;

	};

}