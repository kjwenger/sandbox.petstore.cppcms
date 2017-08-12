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
        dispatcher().map("GET", "/login", &user::login_user, this);
        // GET /user/logout Logs out current logged in user session
        dispatcher().map("GET", "/logout", &user::logout_user, this);
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
        std::pair<void *, size_t> raw_post_data = request().raw_post_data();
        std::string string((const char *) raw_post_data.first, raw_post_data.second);
        std::istringstream is(string);
        cppcms::json::value users;
        is >> users;

        response().out() << users;
    }

    void user::create_user_with_list() {
        std::pair<void *, size_t> raw_post_data = request().raw_post_data();
        std::string string((const char *) raw_post_data.first, raw_post_data.second);
        std::istringstream is(string);
        cppcms::json::value users;
        is >> users;

        response().out() << users;
    }

    void user::login_user() {
        const std::string & query_string = request().query_string();
        std::cerr << "user::login_user() query_string: " << query_string << std::endl;
        const std::string ampersand("&");
        std::vector<std::string> tokens;
        size_t begin = 0, end;
        while ((end = query_string.find(ampersand, begin)) != std::string::npos) {
            std::string token = query_string.substr(begin, end - begin);
            tokens.push_back(token);
            begin = end + 1;
        }
        if (begin < query_string.length()) {
            std::string token = query_string.substr(begin, query_string.length() - begin);
            tokens.push_back(token);
        }
        std::ostringstream os;
        std::copy(tokens.begin(), tokens.end(), std::ostream_iterator<std::string>(os, ","));
        std::cerr << "user::login_user() tokens: " << os.str() << std::endl;
        cppcms::json::value login;
        const std::string equals("=");
        for(std::vector<std::string>::const_iterator
                iterator = tokens.begin();
                iterator != tokens.end();
                iterator ++) {
            const std::string & token = *iterator;
            std::string key;
            std::string value;
            if ((end = token.find(equals)) != std::string::npos) {
                key = token.substr(0, end);
                std::cerr << "user::login_user key: " << key << std::endl;
                size_t count = token.length() - end - 1;
                value = token.substr(end + 1, count);
                std::cerr << "user::login_user value: " << value << std::endl;
                login[key] = value;
            }
        }

        cppcms::json::value user;
        USER(user)

        if (user["username"] == login["username"]
                && user["password"] == login["password"]) {
            response().out() << login["username"];
        } else {
            response().status(400);
        }
    }

    void user::logout_user() {
        response().status(200);
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
