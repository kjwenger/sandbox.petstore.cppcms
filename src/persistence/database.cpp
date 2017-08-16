#include <iostream>
#include <sstream>

#include <sqlite3.h>

#include "persistence/database.hpp"
#include "persistence/persistence_exception.hpp"
#include "persistence/pet.hpp"
#include "persistence/user.hpp"

namespace sandbox_cppcms {
namespace persistence {

    database::database(const std::string & target)
            : db(target + std::string(".db")) {
                                                                                                                        std::cerr << "database::database(\"" << target << "\")" << std::endl;
        sqlite3_config(SQLITE_CONFIG_URI, 0);
        db.registerBeanClass<pet>();
    }

    database::~database() {

    }

    template <class T, class C>
    void database::_list(std::vector<T> &pets) {
        std::vector<hiberlite::bean_ptr<pet>> allBeans = db.getAllBeans<C>();
        pets.clear();
        for (typename std::vector<hiberlite::bean_ptr<C>>::iterator
                iterator = allBeans.begin();
                iterator != allBeans.end();
                iterator ++) {
            hiberlite::bean_ptr<C> & bean_ptr = *iterator;
                                                                                                                        std::cerr << "database::_list() bean_ptr.destroyed(): " << bean_ptr.destroyed() << std::endl;
            if (bean_ptr.destroyed()) continue;
                                                                                                                        std::cerr << "database::_list() *bean_ptr: " << *bean_ptr << std::endl;
            pets.push_back(T(*bean_ptr));
        }
    }

    template <class T, class C>
    T database::_create(const T & pet) {
                                                                                                                        std::cerr << "T database::_create(" << pet << ")" << std::endl;
        C newPet(pet);
        hiberlite::bean_ptr<C> copiedBean = db.copyBean(newPet);
                                                                                                                        std::cerr << "T database::_create(...) copiedBean.destroyed(): " << copiedBean.destroyed() << std::endl;
                                                                                                                        std::cerr << "T database::_create(...) *copiedBean: " << *copiedBean << std::endl;
        T returnPet(*copiedBean);
                                                                                                                        std::cerr << "T database::_create(...) returnPet: " << returnPet << std::endl;
        return returnPet;
    }

    template <class T, class C>
    T database::_read(int id) {
        hiberlite::bean_ptr<C> loadedBean = db.loadBean<C>((hiberlite::sqlid_t) id);
                                                                                                                        std::cerr << "T database::_read(" << id << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
                                                                                                                        std::cerr << "T database::_read(" << id << ") *loadedBean: " << *loadedBean << std::endl;
        T returnPet(*loadedBean);
        return returnPet;
    }

    template <>
    model::pet database::_update<model::pet, ::pet>(const model::pet & pet) {
        hiberlite::bean_ptr<::pet> loadedBean = db.loadBean<::pet>((hiberlite::sqlid_t) pet.id);
                                                                                                                        std::cerr << "model::pet database::_update(" << pet << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
        loadedBean->name = pet.name;
        loadedBean->photoUrls = pet.photoUrls;
        loadedBean->tags = pet.tags;
        loadedBean->status = pet.status;
        model::pet returnPet(*loadedBean);
        return returnPet;
    }
    template <>
    model::user database::_update<model::user, ::user>(const model::user & user) {
        hiberlite::bean_ptr<::user> loadedBean = db.loadBean<::user>((hiberlite::sqlid_t) user.id);
                                                                                                                        std::cerr << "model::user database::_update(" << user << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
        loadedBean->username = user.username;
        loadedBean->firstName = user.firstName;
        loadedBean->lastName = user.lastName;
        loadedBean->email = user. email;
        loadedBean->password = user.password;
        loadedBean->phone = user.phone;
        loadedBean->userStatus = user.userStatus;
        model::user returnPet(*loadedBean);
        return returnPet;
    }

    template <class T, class C>
    T database::_update(const T & pet) {
        hiberlite::bean_ptr<C> loadedBean = db.loadBean<C>((hiberlite::sqlid_t) pet.id);
                                                                                                                        std::cerr << "T database::_update(" << pet << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
        T returnPet(*loadedBean);
        return returnPet;
    }

    template <class T, class C>
    void database::_delet(int id) {
        hiberlite::bean_ptr<C> loadedBean = db.loadBean<C>((hiberlite::sqlid_t) id);
                                                                                                                        std::cerr << "void database::_delete(" << id << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
        loadedBean.destroy();
                                                                                                                        std::cerr << "void database::_delete(...) loadedBean.destroy();" << std::endl;
    }

    void database::init() {
        db.dropModel();
        db.createModel();
    }

    template model::pet database::_create<model::pet, ::pet>(const model::pet & pet);
    template model::pet database::_read<model::pet, ::pet>(int id);
    template model::pet database::_update<model::pet, ::pet>(const model::pet & pet);
    template void database::_delet<model::pet, ::pet>(int id);
    template void database::_list<model::pet, ::pet>(std::vector<model::pet> & pets);

    template <> model::pet database::create(const model::pet & pet) {
        return database::_create<model::pet, ::pet>(pet);
    }
    template <> model::pet database::read(int id) {
        return database::_read<model::pet, ::pet>(id);
    }
    template <> model::pet database::update(const model::pet & pet) {
        return database::_update<model::pet, ::pet>(pet);
    }
    template <> void database::delet<model::pet>(int id) {
        database::_delet<model::pet, ::pet>(id);
    }
    template <> void database::list<model::pet>(std::vector<model::pet> & pets) {
        return database::_list<model::pet, ::pet>(pets);
    }

} /* namespace persistence */
} /* namespace sandbox_cppcms */

sandbox_cppcms::persistence::database * service_database = nullptr;