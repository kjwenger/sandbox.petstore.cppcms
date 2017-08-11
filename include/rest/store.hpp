#pragma once

#include <cppcms/application.h>
#include <cppcms/service.h>

namespace sandbox_cppcms {

class store : public cppcms::application {
public:
    store(cppcms::service& srv);
    virtual ~store();
};

} /* namespace sandbox_cppcms */
