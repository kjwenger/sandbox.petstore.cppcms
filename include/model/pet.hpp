#pragma once

#include <string>
#include <vector>
#include <ostream>

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
    int id;
//    model::category category;
    std::string name;
    std::vector<std::string> photoUrls;
    std::vector<std::string> tags;
    model::pet_status status;
};

} /* namespace model */
} /* namespace sandbox_cppcms */

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::pet & pet);