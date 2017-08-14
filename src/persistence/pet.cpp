#include "persistence/pet.hpp"

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
        val = static_cast<sandbox_cppcms::model::pet_status>(res.get_int(arg));
    }

    template <>
    inline void db_atom<sandbox_cppcms::model::pet_status>::bindValue(sqlite3_stmt* stmt, int col) {
        sqlite3_bind_int(stmt, col, static_cast<int>(val));
    }
}

pet::pet() : sandbox_cppcms::model::pet() { }

pet::pet(const sandbox_cppcms::model::pet & origin)
        : sandbox_cppcms::model::pet(origin) { }

HIBERLITE_EXPORT_CLASS(pet)
