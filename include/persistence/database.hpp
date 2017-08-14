#pragma once

#include <vector>

#include <hiberlite/hiberlite.h>

#include "model/pet.hpp"

namespace sandbox_cppcms {
namespace persistence {

class database {
public:
    database(const std::string & target);
    virtual ~database();

    template <class T, class C>
    T create(const T & pet);
    template <class T, class C>
    T read(int id);
    template <class T, class C>
    T update(const T & pet);
    template <class T, class C>
    T delet(int id);
    template <class T, class C>
    void list(std::vector<T> & pets);
private:
    void init();

    hiberlite::Database db;
};

} /* namespace persistence */
} /* namespace sandbox_cppcms */

extern sandbox_cppcms::persistence::database * service_database;