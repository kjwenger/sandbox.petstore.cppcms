#pragma once

#include <cppcms/application.h>
#include <cppcms/service.h>

namespace sandbox_cppcms {

    /**
     * @see <a href="https://en.wikipedia.org/wiki/Create,_read,_update_and_delete">Create, read, update and delete</a>
     *
     * CRUD (Create, Read, Update, Delete) ... CRUDLS (Create, Read, Update, Delete, List, Search)
     * BREAD (Browse, Read, Edit, Add, Delete)
     * MADS (Modify, Add, Delete, Show)
     * DAVE (Delete, Add, View, Edit)
     * CRAP (Create, Retrieve, Alter, Purge)
     *
     * @see <a href="http://petstore.swagger.io/v2/swagger.json">Swagger Petstore</a>
     * @todo POST /pet/{petId} Updates a pet in the store with form data
     * @todo POST /pet/{petId}/uploadImage uploads an image
     */
    class pet : public cppcms::application {
    public:
        pet(cppcms::service& srv);
        virtual ~pet();
    private:
        // POST /pet Add a new pet to the store
        void create_pet();                                      // C
        // GET /pet/{petId} Find pet by ID                      //
        void read_pet(int id);                                  // R
        // PUT /pet Update an existing pet                      //
        void update_pet();                                      // U
        // DELETE /pet/{petId} Deletes a pet                    //
        void delete_pet(int id);                                // D
        void list_pet();                                        // L
        // GET /pet/findByStatus Finds Pets by status           //
        void search_pet_by_status();                            // S
        // GET /pet/findByTags Finds Pets by tags               //
        void search_pet_by_tags();                              // S
    };

} /* namespace sandbox_cppcms */
