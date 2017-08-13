#pragma once

#include <hiberlite/hiberlite.h>

#include <vector>

#include "model/Pet.hpp"

namespace sandbox_cppcms {

class database {
public:
    database();
    virtual ~database();

//    Pet & createPet(const Pet const & pet);
    void list_pets(std::vector<model::Pet> &pets);
private:
    void init();

    hiberlite::Database db;
};

} /* namespace sandbox_cppcms */
