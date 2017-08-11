#include "rests.hpp"

#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>

namespace sandbox_cppcms {

rests::rests(cppcms::service& srv) : cppcms::application(srv) {
    dispatcher().map("GET","", &rests::get_info, this);
};

rests::~rests() {

}

void rests::get_info() {
    cppcms::json::value info;
    info["name"] = "sandbox-cppcms";
    info["version"] = "0.1.0";

    response().out() << info;
}

} /* namespace sandbox_cppcms */
