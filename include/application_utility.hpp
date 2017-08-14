#pragma once

#include <cppcms/json.h>

namespace sandbox_cppcms {

    class application_utility {
    public:
        static const std::string get_string(
                const cppcms::json::value & settings,
                const std::string & path,
                const std::string & default_value);
        static const bool get_boolean(
                const cppcms::json::value & settings,
                const std::string & path,
                const bool default_value);
    };

} /* namespace sandbox_cppcms */
