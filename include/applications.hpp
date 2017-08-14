#pragma once

#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>

#include "persistence/database.hpp"

namespace sandbox_cppcms {

/**
 *
 */
class applications : public cppcms::application {
public:
    /**
     *
     * @param srv
     */
    applications(cppcms::service& srv);
private:
    persistence::database database;
};

} /* namespace sandbox_cppcms */
