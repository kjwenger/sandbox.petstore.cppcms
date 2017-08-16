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
    pet();
    pet(const int id,
        const std::string & name,
        const std::vector<std::string> & photoUrls,
        const std::vector<std::string> & tags,
        const model::pet_status status);
    pet(const pet & origin);
    bool operator==(const pet & that) const;

    int id;
//    model::category category;
    std::string name;
    std::vector<std::string> photoUrls;
    std::vector<std::string> tags;
    pet_status status;
};

} /* namespace model */
} /* namespace sandbox_cppcms */

const std::string & to_string(const sandbox_cppcms::model::pet_status & pet_status);
sandbox_cppcms::model::pet_status to_pet_status(const std::string & string);
std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::pet_status & pet_status);
std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::pet & pet);
std::ostream & operator<<(std::ostream & os, const std::vector<sandbox_cppcms::model::pet> & pets);
