#pragma once

namespace cppconfiguration
{
	template<typename T>
	class option
	{
	public:
		static T get_value()
		{
			return m_value;
		}
	private:
		friend class configuration_builder;

		static T m_value;
	};

	template<typename T>
	T option<T>::m_value;
}