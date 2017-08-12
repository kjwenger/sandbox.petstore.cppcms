#pragma once

#include <cppcms/application.h>
#include <cppcms/service.h>

namespace sandbox_cppcms {

    class store : public cppcms::application {
    public:
        store(cppcms::service& srv);
        virtual ~store();
    private:
        // POST /store/order Place an order for a pet
        void create_store_order();
        // GET /store/order/{orderId} Find purchase order by ID
        void read_store_order(int id);
        // DELETE /store/order/{orderId} Delete purchase order by ID
        void delete_store_order(int id);
        // GET /store/inventory Returns pet inventories by status
        void list_store_inventory();
    };

} /* namespace sandbox_cppcms */
