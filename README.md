# sandbox.cppcms
Sandbox for C++/CppCMS/Boost PetStore

- Motivation: which technology is best ... is C++ old news?
    - A Bird's View: PetStore RESTful Web API implemented using ...
        - Reference API: Swagger PetStore
        - Definiton JSON: (downloaded) [sandbox.petstore](../sandbox.petstore/README.md)
    - GoLang: goes from _Embedded_ to _Cloud_, replacing C++?
        - Code auto-generated: [sandbox.petstore.golang](../sandbox.petstore.golang/README.md)
    - Elixir/Phoenix: *the* Formel von _Embedded_ bis _Cloud_? Ruby on Rails w/o Ruby?
        - Code auto-generated: [sandbox.petstore.erlang](../sandbox.petstore.erlang/README.md)
    - C++/CppCMS: _Embedded_, _Cloud_, anything ... but at what price?
        - Code auto-generated: [sandbox.petstore.cppcms](../sandbox.petstore.cppcms/README.md)
    - Kotlin/Spring: _Embedded_? Certainly _Cloud_? Simpler than Java EE?
        - Code auto-generated: [..](http://)
    - Node.js: _Cloud_, yes! _Embedded_, maybe?
        - Code auto-generated: [sandbox.petstore.nodejs](../sandbox.petstore.nodejs/README.md)

## Part 1: Setting up C++ Development

- Package Management: from OS - `apt`
    - The Good
        - Built into OS ... or saddled onto
        - Support of multiple Architectures
        - Debian rules
    - The Bad
        - Frequent Clashes
        - Repository Hell (FrankenDebian)
        - Ubuntu sucks at Cross-Compiling
    - The How
        - Install Prerequisites:
            - Network Tools: `apt install curl, wget`
            - Build Tools: `apt install build-essential, cmake, gcc, g++`
            - Libraries: `apt install libssl-dev, ...`
            - Version Control: `apt install git, subversion`
- Project Management: CMake - because it works!
    - The Good
        - Supported:
            - IDE CLion
            - Good Community
                - Blogs, Forums, StackOverflow
                - Many Add-ons
        - Accepted:
            - C++ Projects world-wide
        - Powerful:
            - Handles multi-module/target Projects
        - Structured:
            - Hierarchical
        - Simple: ... simpler than `make`, _Auto-tools_
            - Intuitive Build Script Language
    - The Bad
        - Learning Curve
        - Discrepancies in Package Management
    - The How
        - Build Instructions: [CMakeList](./CMakeList.txt)
        - Source: [main](./src/main.cpp)
        - Destination Directory: [build](./build)
        - Configuration: `cmake ..`
        - Building: `make`
