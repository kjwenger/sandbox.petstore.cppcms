#include "rest/user.hpp"

#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>

#define USER(user)\
    user["id"] = 1;\
    user["username"] = "string";\
    user["firstName"] = "string";\
    user["lastName"] = "string";\
    user["email"] = "string";\
    user["password"] = "string";\
    user["phone"] = "string";\
    user["userStatus"] = 0;\

namespace sandbox_cppcms {

    user::user(cppcms::service &srv) : cppcms::application(srv) {
        // POST /user Create user
        dispatcher().map("POST", "", &user::create_user, this);
        // POST /user/createWithArray Creates list of users with given input array
        dispatcher().map("POST", "/createWithArray", &user::create_user_with_array, this);
        // POST /user/createWithList Creates list of users with given input array
        dispatcher().map("POST", "/createWithList", &user::create_user_with_list, this);
        // GET /user/login Logs user into the system
        dispatcher().map("GET", "", &user::login_user, this);
        // GET /user/logout Logs out current logged in user session
        dispatcher().map("GET", "", &user::logout_user, this);
        // GET /user/{username} Get user by user name
        dispatcher().map("GET", "/(\\w+)", &user::read_user, this, 1);
        // PUT /user/{username} Updated user
        dispatcher().map("PUT", "/(\\w+)", &user::update_user, this, 1);
        // DELETE /user/{username} Delete user
        dispatcher().map("DELETE", "/(\\w+)", &user::delete_user, this, 1);
    }

    user::~user() {

    }

    void user::create_user() {
        std::pair<void *, size_t> raw_post_data = request().raw_post_data();
        std::string string((const char *) raw_post_data.first, raw_post_data.second);
        std::istringstream is(string);
        cppcms::json::value user;
        is >> user;

        response().out() << user;
    }

    void user::create_user_with_array() {

    }

    void user::create_user_with_list() {

    }

    void user::login_user() {

    }

    void user::logout_user() {

    }

    void user::read_user(const std::string & username) {
        cppcms::json::value user;
        USER(user)

        response().out() << user;
    }

    void user::update_user(const std::string & username) {
        std::pair<void *, size_t> raw_post_data = request().raw_post_data();
        std::string content((const char *) raw_post_data.first, raw_post_data.second);
        std::cerr << "user::update_user() content: " << content << std::endl;
        std::istringstream is(content);
        cppcms::json::value user;
        is >> user;
        std::cerr << "user::update_user() user: " << user << std::endl;

        response().out() << user;
    }

    void user::delete_user(const std::string & username) {
        response().status(200);
    }

} /* namespace sandbox_cppcms */
