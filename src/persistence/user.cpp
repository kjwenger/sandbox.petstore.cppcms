#include "persistence/user.hpp"

user::user() : sandbox_cppcms::model::user() { }

user::user(
        const int id,
        const std::string & username,
        const std::string & firstName,
        const std::string & lastName,
        const std::string & email,
        const std::string & password,
        const std::string & phone,
        const int userStatus)
    : sandbox_cppcms::model::user(id, username, firstName, lastName, email, password, phone, userStatus) { }

user::user(const sandbox_cppcms::model::user & origin)
    : sandbox_cppcms::model::user(origin) { }

HIBERLITE_EXPORT_CLASS(user)
