#pragma once

#include "cppconfiguration/configuration_root.h"

#include <string>

namespace cppconfiguration
{
	std::optional<configuration_section> configuration_root::get_section(const std::string& key) const
	{
		return m_section.get_section(key);
	}

	std::optional<configuration_section> configuration_root::get_section(const char* key) const
	{
		return m_section.get_section(key);
	}

	std::vector<configuration_section> configuration_root::get_children() const
	{
		return m_section.get_children();
	}
}