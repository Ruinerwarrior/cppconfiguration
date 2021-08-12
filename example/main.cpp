#include <cppconfiguration/configuration_builder.h>
#include <cppconfiguration/option.h>

#include <iostream>
#include <string>

using namespace cppconfiguration;

struct database_options
{
	static std::string key;

	std::string connection_string;
};

std::string database_options::key = "DatabaseOptions";

database_options configure(const configuration_section& section)
{
	database_options options;
	options.connection_string = section.get_value<std::string>("ConnectionString").value_or("fake_connection_string");

	return options;
}

int main()
{
	auto config = configuration_builder()
		.add_json_file("appsettings.json")
		.configure<database_options>(database_options::key, &configure)
		.build();

	// using config variable, only locally available
	auto connectionStringThroughConfig = config
		.get_section("DatabaseOptions")
		.value()
		.get_value<std::string>("ConnectionString")
		.value_or("fake_connection_string");

	// using previously configured option, globally available
	auto connectionStringThroughOption = option<database_options>::get_value().connection_string;
}
