#include "model/user.hpp"


namespace sandbox_cppcms {
namespace model {

    user::user()
        : id(0)
        , username("")
        , firstName("")
        , lastName("")
        , email("")
        , password("")
        , phone("")
        , userStatus(0) { }
    user::user(
            const int id,
            const std::string & username,
            const std::string & firstName,
            const std::string & lastName,
            const std::string & email,
            const std::string & password,
            const std::string & phone,
            const int userStatus)
        : id(id)
        , username(username)
        , firstName(firstName)
        , lastName(lastName)
        , email(email)
        , password(password)
        , phone(phone)
        , userStatus(userStatus) { }
    user::user(const sandbox_cppcms::model::user & origin)
        : id(origin.id)
        , username(origin.username)
        , firstName(origin.firstName)
        , lastName(origin.lastName)
        , email(origin.email)
        , password(origin.password)
        , phone(origin.phone)
        , userStatus(origin.userStatus) { }

} /* namespace model */
} /* namespace sandbox_cppcms */

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::user & user) {
    return os << user.id << ",\"" << user.username << "\"";
}