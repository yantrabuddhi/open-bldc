#ifndef REGISTER_GROUP_CONFIG_HPP__
#define REGISTER_GROUP_CONFIG_HPP__

#include <string>
#include <vector>

#include "register_config.hpp"

class RegisterGroupConfig : public Config
{

private: 
	
	::std::string m_name; 
	::std::map< ::std::string, ::std::string > m_properties; 
	::std::vector<RegisterConfig> m_register_configs; 

	::std::string m_description;

public: 

	RegisterGroupConfig() 
	: m_name(""), m_description("")	{ }

	RegisterGroupConfig(::std::string const & name)
	: m_name(name), m_description("") { }

	~RegisterGroupConfig() { }

	inline ::std::string const & name(void) const { 
		return m_name; 
	}

	inline void add_register(const RegisterConfig & register_config) { 
		m_register_configs.push_back(register_config); 
	}
	inline ::std::vector<RegisterConfig> const & registers(void) const { 
		return m_register_configs;
	}

	inline void set_description(const ::std::string & description) { 
		m_description = description; 
	}
	inline void set_description(yaml_char_t * description) {
		m_description = ::std::string((const char * )(description)); 
	}

	inline void set_properties(const ::std::map< ::std::string, ::std::string> & props) { 
		m_properties = props;
	}

	inline void log(void) const { 
		LOG_INFO_PRINT("Register group %s", m_name.c_str());
		
		::std::map< ::std::string, ::std::string>::const_iterator p_it; 
		::std::map< ::std::string, ::std::string>::const_iterator p_end = m_properties.end(); 
		for(p_it = m_properties.begin(); p_it != p_end; ++p_it) { 
			LOG_INFO_PRINT("  %s -> %s", (*p_it).first.c_str(), (*p_it).second.c_str());
		}

		::std::vector<RegisterConfig>::const_iterator it; 
		::std::vector<RegisterConfig>::const_iterator end = m_register_configs.end(); 
		for(it = m_register_configs.begin(); it != end; ++it) { 
				(*it).log(); 
		}
	}
	
};

#endif