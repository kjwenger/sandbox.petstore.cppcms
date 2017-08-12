#include "rest/v2.hpp"
#include "rest/pet.hpp"
#include "rest/store.hpp"
#include "rest/user.hpp"

#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>

namespace sandbox_cppcms {

    v2::v2(cppcms::service& srv) : cppcms::application(srv) {
        cppcms::application::attach(new pet(srv),
                "pet",
                "/pet{1}", // mapping
                "/pet((.*))?", // dispatching
                1);
        cppcms::application::attach(new store(srv),
                "store",
                "/store{1}", // mapping
                "/store((.*))?", // dispatching
                1);
        cppcms::application::attach(new user(srv),
                "user",
                "/user{1}", // mapping
                "/user((.*))?", // dispatching
                1);

        dispatcher().map("GET","", &v2::get_info, this);
    }

    v2::~v2() {

    }

    void v2::get_info() {
        cppcms::json::value info;
        info["name"] = "sandbox-cppcms";
        info["version"] = "0.1.0";

        response().out() << info;
    }

} /* namespace sandbox_cppcms */
