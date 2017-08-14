#pragma once

#include <string>
#include <exception>

namespace sandbox_cppcms {
namespace persistence {

    class database;

    class persistence_exception : public std::exception {
        friend class database;
    public:
        virtual const char* what() const throw() override;
    private:
        persistence_exception();
        persistence_exception(const persistence_exception & origin);
    };

} /* namespace persistence */
} /* namespace sandbox_cppcms */
