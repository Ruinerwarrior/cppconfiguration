#pragma once

#include "configuration_root.h"
#include "option.h"

#include <functional>
#include <vector>

namespace cppconfiguration
{
	class configuration_builder
	{
	public:
		configuration_builder& add_json_file(const std::filesystem::path& path);
		configuration_root build();

		template<typename T>
		configuration_builder& configure(const std::string& key, std::function<T(configuration_section& section)> mapper)
		{
			option<T>::m_value = mapper(m_configuration_root.get_section(key).value());

			return *this;
		}

	private:
		configuration_root m_configuration_root;
	};
}