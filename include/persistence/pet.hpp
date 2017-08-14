#pragma once

#include <hiberlite/hiberlite.h>

#include <string>
#include <vector>

#include "model/pet.hpp"

namespace hiberlite {
    template <class A>
    void hibernate(A& ar, sandbox_cppcms::model::pet_status& value, const unsigned int) {
        ar& db_atom<sandbox_cppcms::model::pet_status>(value);
    }

    template <>
    inline std::string db_atom<sandbox_cppcms::model::pet_status>::sqliteStorageClass() {
        return "INTEGER";
    }

    template <>
    template <class Stmt, class Arg>
    void db_atom<sandbox_cppcms::model::pet_status>::loadValue(Stmt& res, Arg& arg) {
        const int & anInt = res.get_int(arg);
        val = static_cast<sandbox_cppcms::model::pet_status>(anInt);
    }

    template <>
    inline void db_atom<sandbox_cppcms::model::pet_status>::bindValue(sqlite3_stmt* stmt, int col) {
        sqlite3_bind_int(stmt, col, static_cast<int>(val));
    }
}

class pet : public sandbox_cppcms::model::pet {
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive& ar) {
        ar & HIBERLITE_NVP(id);
        ar & HIBERLITE_NVP(name);
        ar & HIBERLITE_NVP(photoUrls);
        ar & HIBERLITE_NVP(tags);
        ar & HIBERLITE_NVP(status);
    }
public:
    pet();
    pet(const int id,
        const std::string & name,
        const std::vector<std::string> & photoUrls,
        const std::vector<std::string> & tags,
        const sandbox_cppcms::model::pet_status status);
    pet(const sandbox_cppcms::model::pet & origin);
};
