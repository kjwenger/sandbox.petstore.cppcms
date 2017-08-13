#pragma once

#include <hiberlite/hiberlite.h>

#include <string>
#include <vector>

namespace sandbox_cppcms {

class Category {
public:
    int id;
    std::string name;
};

enum PetStatus {
    available,
    pending,
    sold
};

class Pet {
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive& ar) {
        ar & HIBERLITE_NVP(name);
        ar & HIBERLITE_NVP(photoUrls);
        ar & HIBERLITE_NVP(tags);
//        ar & HIBERLITE_NVP(status);
    }
public:
    int id;
//    Category category;
    std::string name;
    std::vector<std::string> photoUrls;
    std::vector<std::string> tags;
//    PetStatus status;
};

} /* namespace sandbox_cppcms */

HIBERLITE_EXPORT_CLASS(sandbox_cppcms::Pet)
