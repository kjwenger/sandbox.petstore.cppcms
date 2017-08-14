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

    void init();

    template <class T>
    T create(const T & pet) { T t; return t; }
    template <class T>
    T read(int id) { T t; return t; }
    template <class T>
    T update(const T & pet) { T t; return t; }
    template <class T>
    T delet(int id) { T t; return t; }
    template <class T>
    void list(std::vector<T> & pets) { }
private:
    template <class T, class C>
    T _create(const T & pet);
    template <class T, class C>
    T _read(int id);
    template <class T, class C>
    T _update(const T & pet);
    template <class T, class C>
    T _delet(int id);
    template <class T, class C>
    void _list(std::vector<T> & pets);

    hiberlite::Database db;
};

} /* namespace persistence */
} /* namespace sandbox_cppcms */

extern sandbox_cppcms::persistence::database * service_database;