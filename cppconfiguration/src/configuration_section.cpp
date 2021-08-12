#include "cppconfiguration/configuration_section.h"

namespace cppconfiguration
{
	std::optional<configuration_section> configuration_section::get_section(const std::string& key) const
	{
		if (auto it = m_json.find(key); it != m_json.end())
			return std::optional{ configuration_section(key, *it) };

		return std::nullopt;
	}

	std::vector<configuration_section> configuration_section::get_children() const
	{
		std::vector<configuration_section> sections;

		for (auto& el : m_json.items())
			sections.emplace_back(el.key(), el.value());

		return sections;
	}

	const std::string& configuration_section::get_key() const
	{
		return m_key;
	}
}