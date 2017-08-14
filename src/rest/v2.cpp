#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>

#include <cppcms/json.h>

#include "rest/v2.hpp"
#include "rest/pet.hpp"
#include "rest/store.hpp"
#include "rest/user.hpp"

namespace sandbox_cppcms {

    v2::v2(cppcms::service & srv)
            : cppcms::application(srv)
            , settings(srv.settings()) {
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
        std::cerr << "v2::get_info() settings: " << settings;
        cppcms::json::value info = settings.find("application.info");
        response().out() << info;
    }

} /* namespace sandbox_cppcms */
