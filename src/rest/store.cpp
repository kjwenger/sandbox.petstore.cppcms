#include "rest/store.hpp"

#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>

namespace sandbox_cppcms {

store::store(cppcms::service& srv) : cppcms::application(srv) {

};

store::~store() {

}

} /* namespace sandbox_cppcms */
