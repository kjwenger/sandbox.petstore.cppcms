#include "applications.hpp"
#include "rest/rests.hpp"

namespace sandbox_cppcms {

applications::applications(cppcms::service& srv)
        : cppcms::application(srv) {
    cppcms::application::attach(new rests(srv),
            "v2",
            "/v2{1}", // mapping
            "/v2((.*))?", // dispatching
            1);
}

} /* namespace sandbox_cppcms */
