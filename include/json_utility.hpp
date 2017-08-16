#pragma once

#include <cppcms/json.h>

#include "model/pet.hpp"

namespace sandbox_cppcms {

    class json_utility {
    public:
        static cppcms::json::value & copy(const sandbox_cppcms::model::pet & pet, cppcms::json::value & value);
        static sandbox_cppcms::model::pet & copy(const cppcms::json::value & value, sandbox_cppcms::model::pet & pet);
    };

} /* namespace sandbox_cppcms */
