#pragma once

#include "SR_PCH.h"
#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	template <typename T>
	class SR_DirtyFlag : public SR_NonCopyable
	{
	public:
		explicit SR_DirtyFlag() noexcept;

		bool Check() const;
		void Reset();

		void SetValue(const T & value) { m_curValue = value; }

		const T & GetValue() const noexcept { return m_curValue; }
		const T * GetAddressOf() const noexcept { return &m_curValue; }

	protected:
		T m_curValue;
		T m_oldValue;

	};

	template <typename T, unsigned SIZE>
	class SR_DirtyFlagArray
	{
	public:
		explicit SR_DirtyFlagArray() noexcept;

		bool Check() const;
		void Reset();

		void SetValue(int index, const T & value);
		void SetValueAll(const T & value);

		unsigned GetStart() const noexcept { return m_start; }
		unsigned GetEnd() const noexcept { return m_end; }
		unsigned GetRange() const noexcept { return m_end - m_start + 1; }
		const T & GetValue(unsigned index) const noexcept { return m_curValues[index]; }
		const T * GetAddressOf(unsigned index) const noexcept { return &m_curValues[index]; }
		const T * GetValueArray() const noexcept { return m_curValues; }

	protected:
		int m_start;
		int m_end;
		T m_curValues[SIZE];
		T m_oldValues[SIZE];

	};

};

#include "SR_DirtyFlag.inl"