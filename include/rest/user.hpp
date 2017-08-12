#pragma once

#include <cppcms/application.h>
#include <cppcms/service.h>

namespace sandbox_cppcms {

class user : public cppcms::application {
public:
    user(cppcms::service& srv);
    virtual ~user();
private:
    // POST /user Create user
    void create_user();
    // POST /user/createWithArray Creates list of users with given input array
    void create_user_with_array();
    // POST /user/createWithList Creates list of users with given input array
    void create_user_with_list();
    // GET /user/login Logs user into the system
    void login_user();
    // GET /user/logout Logs out current logged in user session
    void logout_user();
    // GET /user/{username} Get user by user name
    void read_user(const std::string & username);
    // PUT /user/{username} Updated user
    void update_user(const std::string & username);
    // DELETE /user/{username} Delete user
    void delete_user(const std::string & username);
};

} /* namespace sandbox_cppcms */
