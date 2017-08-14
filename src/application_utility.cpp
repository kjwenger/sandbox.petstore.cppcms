#include <iostream>
#include <sstream>

#include <cppcms/json.h>

#include "application_utility.hpp"

namespace sandbox_cppcms {

    const std::string application_utility::get_string(
            const cppcms::json::value & settings,
            const std::string & path,
            const std::string & default_value) {
//        std::cerr << "application_utility::get_string(..) settings: " << settings << std::endl;
//        std::cerr << "application_utility::get_string(..) path: " << path << std::endl;
        cppcms::json::value found_value = settings.find(path);
//        std::cerr << "application_utility::get_string(..) found_value: " << found_value << std::endl;
        if (found_value.is_undefined() ||
            found_value.is_null()) {
            return default_value;
        }
        switch (found_value.type()) {
            case cppcms::json::is_string: {
                const std::string & str = found_value.str();
                return str; }
            case cppcms::json::is_number: {
                std::ostringstream oss;
                oss << found_value.number();
                std::string str = oss.str();
                return str; }
            case cppcms::json::is_boolean: {
                std::ostringstream oss;
                oss << found_value.boolean();
                std::string str = oss.str();
                return str; }
            default:
                return default_value;
        }
    }

    const bool get_boolean(
            const cppcms::json::value & settings,
            const std::string & path,
            const bool default_value) {
        cppcms::json::value found_value = settings.find(path);
        if (found_value.is_undefined() ||
            found_value.is_null()) {
            return default_value;
        }
        switch (found_value.type()) {
            case cppcms::json::is_string: {
                const std::string & str = found_value.str();
                return str.compare("true") == 0 ? true : false; }
            case cppcms::json::is_number: {
                double number = found_value.number();
                return number != 0.0; }
            case cppcms::json::is_boolean: {
                bool boolean = found_value.boolean();
                return boolean; }
            default:
                return default_value;
        }
    }

} /* namespace sandbox_cppcms */
