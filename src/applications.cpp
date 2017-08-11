#include "applications.hpp"
#include "rest/v2.hpp"

namespace sandbox_cppcms {

applications::applications(cppcms::service& srv)
        : cppcms::application(srv) {
    cppcms::application::attach(new v2(srv),
            "v2",
            "/v2{1}", // mapping
            "/v2((.*))?", // dispatching
            1);
}

} /* namespace sandbox_cppcms */
