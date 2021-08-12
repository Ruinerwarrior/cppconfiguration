#pragma once

#include "configuration_section.h"

#include <nlohmann/json.hpp>

#include <optional>
#include <filesystem>
#include <unordered_map>

namespace cppconfiguration
{
	class configuration_root
	{
	public:
		std::optional<configuration_section>	get_section(const std::string& key);
		std::vector<configuration_section>		get_children();

		template<typename T> 
		std::optional<T> get_value(std::string& key)
		{
			return m_section.get_value<T>(key);
		}

		template<typename T>
		std::optional<T> get_value(const char* key)
		{
			return m_section.get_value<T>(key);
		}

		template<typename T>
		std::optional<T> get_value()
		{
			return m_section.get_value<T>();
		}

	private:
		friend class configuration_builder;

		configuration_section m_section;
	};
}