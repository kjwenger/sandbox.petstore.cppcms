#pragma once

#include <cppcms/application.h>
#include <cppcms/service.h>

namespace sandbox_cppcms {

class user : public cppcms::application {
public:
    user(cppcms::service& srv);
    virtual ~user();

    void create_user();
    void read_user(int id);
    void update_user(int id);
    void delete_user(int id);
};

} /* namespace sandbox_cppcms */
