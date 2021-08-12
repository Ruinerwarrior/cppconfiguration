#include "cppconfiguration/configuration_builder.h"

#include <nlohmann/json.hpp>

#include <filesystem>
#include <fstream>

namespace cppconfiguration
{
	using namespace nlohmann;

	configuration_builder& configuration_builder::add_json_file(const std::filesystem::path& path)
	{
		if (std::filesystem::exists(path))
		{
			std::ifstream ifs(path.string());
			m_configuration_root.m_section.m_json.update(nlohmann::json::parse(ifs));
		}

		return *this;
	}

	configuration_root configuration_builder::build()
	{
		return m_configuration_root;
	}
}