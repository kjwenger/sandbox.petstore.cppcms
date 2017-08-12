#include "rest/user.hpp"

#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>

namespace sandbox_cppcms {

    user::user(cppcms::service &srv) : cppcms::application(srv) {
        dispatcher().map("POST", "", &user::create_user, this);
        dispatcher().map("GET", "/(\\d+)", &user::read_user, this, 1);
        dispatcher().map("PUT", "/(\\d+)", &user::update_user, this, 1);
        dispatcher().map("DELETE", "/(\\d+)", &user::delete_user, this, 1);
    }

    user::~user() {

    }

    void user::create_user() {
        cppcms::json::value user;

        response().out() << user;
    }

    void user::read_user(int id) {
        cppcms::json::value user;

        response().out() << user;
    }

    void user::update_user(int id) {
        cppcms::json::value user;

        response().out() << user;
    }

    void user::delete_user(int id) {
        cppcms::json::value user;

        response().out() << user;
    }

} /* namespace sandbox_cppcms */
