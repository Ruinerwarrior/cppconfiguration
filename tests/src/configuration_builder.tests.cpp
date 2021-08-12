#include <cppconfiguration/configuration_builder.h>

#include <catch.hpp>

#include <string>
#include <filesystem>

using namespace cppconfiguration;

SCENARIO("creating the configuration builder")
{
	configuration_builder builder;

	GIVEN("a valid path to an empty json file")
	{
		std::filesystem::path path = "appsettings_empty.json";

		REQUIRE(std::filesystem::exists(path));
		REQUIRE(path.extension() == ".json");

		WHEN("adding the json file to the builder")
		{
			builder.add_json_file(path);

			THEN("configuration_root should not have children")
			{
				configuration_root root = builder.build();
				REQUIRE(root.get_children().size() == 0);
			}

			THEN("configuration_root should return nullopt when getting by key")
			{
				configuration_root root = builder.build();
				REQUIRE(!root.get_value<std::string>("key").has_value());
			}

			THEN("configuration_root should throw when casting section to invalid type")
			{
				configuration_root root = builder.build();
				REQUIRE_THROWS(root.get_value<std::string>());
			}
		}
	}
}