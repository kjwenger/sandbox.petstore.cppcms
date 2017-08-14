#pragma once

#include <string>
#include <vector>
#include <ostream>

namespace sandbox_cppcms {
namespace model {

class Category {
public:
    int id;
    std::string name;
};

enum PetStatus {
    available,
    pending,
    sold
};

class Pet {
public:
    int id;
//    Category category;
    std::string name;
//    std::vector<std::string> photoUrls;
//    std::vector<std::string> tags;
//    PetStatus status;
};

} /* namespace model */
} /* namespace sandbox_cppcms */

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::Pet & pet);