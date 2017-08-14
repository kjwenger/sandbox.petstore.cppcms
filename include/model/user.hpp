#pragma once

#include <string>
#include <vector>
#include <ostream>

namespace sandbox_cppcms {
namespace model {

class user {
public:
    user();
    user(const int id,
        const std::string & username,
        const std::string & firstName,
        const std::string & lastName,
        const std::string & email,
        const std::string & password,
        const std::string & phone,
        const int userStatus);
    user(const user & origin);

    int id;
    std::string username;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string password;
    std::string phone;
    int userStatus;
};

} /* namespace model */
} /* namespace sandbox_cppcms */

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::user & user);