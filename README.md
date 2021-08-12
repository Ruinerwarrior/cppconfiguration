# cppconfiguration
cppconfiguration is a library created to help read json configuration files and use the configuration values throughout the application.
Heavily inspired by .NET's option pattern.

# examples
Some simple examples to get started immediatly.

## single json file example
This example shows the most simple situation, a single json file with one object that needs to be mapped.

- json file "appsettings.json"
```json 
{
  "DatabaseOptions": {
    "ConnectionString":  "real_connection_string"
  }
}
```  

- using the json file
```cpp
using namespace cppconfiguration;

// struct where we will map the json object to
struct database_options
{
    std::string connection_string;
};

// method used to map the json object to the struct, can be used to set default values as well
database_options configure_database_options(const configuration_section& section)
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

```
