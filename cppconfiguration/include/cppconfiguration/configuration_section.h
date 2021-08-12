#pragma once

#include <nlohmann/json.hpp>

#include <string>
#include <optional>

namespace cppconfiguration
{
	class configuration_section
	{
	public:
		configuration_section() = default;
		configuration_section(const std::string& key, nlohmann::basic_json<> json)
			:
			m_key(key),
			m_json(json)
		{
		};

		std::optional<configuration_section>	get_section(const std::string& key) const;
		std::vector<configuration_section>		get_children() const;
		const std::string&						get_key() const;

		template<typename T>
		std::optional<T> get_value(const std::string& key) const
		{
			if (auto it = m_json.find(key); it != m_json.end())
				return std::optional{ (*it).get<T>() };

			return std::nullopt;
		}

		template<typename T>
		std::optional<T> get_value() const
		{
			return m_json.get<T>();
		}

	private:
		friend class configuration_builder;

		std::string m_key;
		nlohmann::basic_json<> m_json;
	};
}