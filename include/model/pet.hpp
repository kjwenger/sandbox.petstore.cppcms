#pragma once

#include <string>
#include <vector>
#include <ostream>

#include <cppcms/json.h>

namespace sandbox_cppcms {
namespace model {

class category {
public:
    int id;
    std::string name;
};

enum class pet_status {
    available,
    pending,
    sold
};

class pet {
public:
    pet();
    pet(const int id,
        const std::string & name,
        const std::vector<std::string> & photoUrls,
        const std::vector<std::string> & tags,
        const model::pet_status status);
    pet(const pet & origin);

    int id;
//    model::category category;
    std::string name;
    std::vector<std::string> photoUrls;
    std::vector<std::string> tags;
    pet_status status;
};

} /* namespace model */
} /* namespace sandbox_cppcms */

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::pet & pet);
cppcms::json::value & operator<<(cppcms::json::value & value, const sandbox_cppcms::model::pet & pet);
sandbox_cppcms::model::pet & operator<<(sandbox_cppcms::model::pet & pet, const cppcms::json::value & value);
