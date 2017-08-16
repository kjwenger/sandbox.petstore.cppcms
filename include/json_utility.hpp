#pragma once

#include <cppcms/json.h>

#include "model/pet.hpp"

namespace sandbox_cppcms {

    class json_utility {
    public:
        static cppcms::json::value & copy(cppcms::json::value & value, const sandbox_cppcms::model::pet & pet);
        static sandbox_cppcms::model::pet & copy(sandbox_cppcms::model::pet & pet, const cppcms::json::value & value);
    };

} /* namespace sandbox_cppcms */
