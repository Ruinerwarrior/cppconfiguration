#pragma once

#include "cppconfiguration/configuration_root.h"

#include <string>

namespace cppconfiguration
{
	std::optional<configuration_section> configuration_root::get_section(const std::string& key)
	{
		return m_section.get_section(key);
	}

	std::vector<configuration_section> configuration_root::get_children()
	{
		return m_section.get_children();
	}
}