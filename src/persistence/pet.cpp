#include <iostream>

#include "persistence/pet.hpp"

//namespace hiberlite {
//    template <class A>
//    void hibernate(A& ar, sandbox_cppcms::model::pet_status& value, const unsigned int) {
//        std::cerr << "hiberlite::hibernate(.., " << (int)value << ", ..)" << std::endl;
//        ar& db_atom<sandbox_cppcms::model::pet_status>(value);
//    }
//
//    template <>
//    inline std::string db_atom<sandbox_cppcms::model::pet_status>::sqliteStorageClass() {
//        return "INTEGER";
//    }
//
//    template <>
//    template <class Stmt, class Arg>
//    void db_atom<sandbox_cppcms::model::pet_status>::loadValue(Stmt& res, Arg& arg) {
//        const int & anInt = res.get_int(arg);
//        std::cerr << "hiberlite::loadValue(...) anInt: " << anInt << std::endl;
//        val = static_cast<sandbox_cppcms::model::pet_status>(anInt);
//        std::cerr << "hiberlite::loadValue(...) val: " << (int)val << std::endl;
//    }
//
//    template <>
//    inline void db_atom<sandbox_cppcms::model::pet_status>::bindValue(sqlite3_stmt* stmt, int col) {
//        std::cerr << "hiberlite::bindValue(.., " << col << ")" << std::endl;
//        sqlite3_bind_int(stmt, col, static_cast<int>(val));
//    }
//}

pet::pet() : sandbox_cppcms::model::pet() { }

pet::pet(
        const int id,
        const std::string & name,
        const std::vector<std::string> & photoUrls,
        const std::vector<std::string> & tags,
        const sandbox_cppcms::model::pet_status status)
    : sandbox_cppcms::model::pet(id, name, photoUrls, tags, status) { }

pet::pet(const sandbox_cppcms::model::pet & origin)
    : sandbox_cppcms::model::pet(origin) { }

HIBERLITE_EXPORT_CLASS(pet)
