#pragma once

#include <hiberlite/hiberlite.h>

#include <string>
#include <vector>

#include "model/user.hpp"

class user : public sandbox_cppcms::model::user {
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive& ar) {
        ar & HIBERLITE_NVP(username);
        ar & HIBERLITE_NVP(firstName);
        ar & HIBERLITE_NVP(lastName);
        ar & HIBERLITE_NVP(email);
        ar & HIBERLITE_NVP(password);
        ar & HIBERLITE_NVP(phone);
        ar & HIBERLITE_NVP(userStatus);
    }
public:
    user();
    user(const int id,
        const std::string & username,
        const std::string & firstName,
        const std::string & lastName,
        const std::string & email,
        const std::string & password,
        const std::string & phone,
        const int userStatus);
    user(const sandbox_cppcms::model::user & origin);
};
