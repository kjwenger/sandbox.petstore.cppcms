#pragma once

#include <cppcms/application.h>
#include <cppcms/service.h>

namespace sandbox_cppcms {

class pet : public cppcms::application {
public:
    pet(cppcms::service& srv);
    virtual ~pet();

    void enumerate_pet();
    void create_pet();
    void read_pet(int id);
    void update_pet(int id);
    void delete_pet(int id);
};

} /* namespace sandbox_cppcms */
