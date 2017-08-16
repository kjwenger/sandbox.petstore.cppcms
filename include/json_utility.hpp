#pragma once

#include <string>
#include <vector>

#include <cppcms/json.h>

#include "model/pet.hpp"

namespace sandbox_cppcms {

    class json_utility {
    public:
        static const std::string id;
        static const std::string name;
        static const std::string photoUrls;
        static const std::string tag;
        static const std::string status;

        static const std::vector<std::string> pet_properties;
        static const std::vector<std::string> pet_list_properties;

        static bool is_property(const std::string & property, const std::vector<std::string> & properties);
        static cppcms::json::value & copy(
                const sandbox_cppcms::model::pet & pet,
                cppcms::json::value & value,
                const std::vector<std::string> & properties = pet_properties);
        static cppcms::json::value & copy(
                const std::vector<sandbox_cppcms::model::pet> & pets,
                cppcms::json::value & value,
                const std::vector<std::string> & properties = pet_list_properties);
        static sandbox_cppcms::model::pet & copy(const cppcms::json::value & value, sandbox_cppcms::model::pet & pet);
    };

} /* namespace sandbox_cppcms */
