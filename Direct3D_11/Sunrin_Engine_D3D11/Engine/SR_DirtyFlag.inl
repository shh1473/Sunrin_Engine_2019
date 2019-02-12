#pragma once

namespace SunrinEngine
{

	template <typename T>
	SR_DirtyFlag<T>::SR_DirtyFlag() noexcept
	{

	}

	template <typename T>
	bool SR_DirtyFlag<T>::Check() const
	{
		return (m_curValue != m_oldValue);
	}

	template <typename T>
	void SR_DirtyFlag<T>::Reset()
	{
		m_oldValue = m_curValue;
	}

	template <typename T, unsigned SIZE>
	SR_DirtyFlagArray<T, SIZE>::SR_DirtyFlagArray() noexcept :
		m_start	{ SIZE },
		m_end	{ -1 }
	{

	}

	template <typename T, unsigned SIZE>
	void SR_DirtyFlagArray<T, SIZE>::SetValue(int index, const T & value)
	{
		m_curValues[index] = value;

		if (index < m_start)
		{
			m_start = index;
		}
		else if (index == m_start)
		{
			if (m_curValues[index] == m_oldValues[index])
			{
				for (; m_start < m_end; ++m_start)
				{
					if (m_curValues[m_start] != m_oldValues[m_start])
					{
						break;
					}
				}
			}
		}

		if (index > m_end)
		{
			m_end = index;
		}
		else if (index == m_end)
		{
			if (m_curValues[index] == m_oldValues[index])
			{
				for (; m_end > m_start; --m_end)
				{
					if (m_curValues[m_end] != m_oldValues[m_end])
					{
						break;
					}
				}
			}
		}
	}

	template <typename T, unsigned SIZE>
	void SR_DirtyFlagArray<T, SIZE>::SetValueAll(const T & value)
	{
		for (unsigned i{ 0U }; i < SIZE; ++i)
		{
			m_curValues[i] = value;
		}

		m_start = 0;
		m_end = SIZE - 1U;
	}

	template <typename T, unsigned SIZE>
	bool SR_DirtyFlagArray<T, SIZE>::Check() const
	{
		for (int i{ 0 }; i < m_end + 1; ++i)
		{
			if (m_curValues[i] != m_oldValues[i])
			{
				return true;
			}
		}

		return false;
	}

	template <typename T, unsigned SIZE>
	void SR_DirtyFlagArray<T, SIZE>::Reset()
	{
		for (unsigned i{ 0U }; i < SIZE; ++i)
		{
			m_oldValues[i] = m_curValues[i];
		}

		m_start = SIZE;
		m_end = -1;
	}

}