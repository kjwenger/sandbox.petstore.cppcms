#pragma once

#include <cppcms/application.h>
#include <cppcms/service.h>

#include <cppcms/json.h>

namespace sandbox_cppcms {

class v2 : public cppcms::application {
public:
    v2(cppcms::service & srv);
    virtual ~v2();

    void get_info();
private:
    const cppcms::json::value & settings;
};

} /* namespace sandbox_cppcms */
