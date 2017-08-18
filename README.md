# sandbox.petstore.cppcms

Sandbox for C++/CppCMS/Boost PetStore

- Motivation: which technology is best ... is C++ old news?
    - A Bird's-Eye View: PetStore RESTful Web API implemented using ...
        - Reference API: [Swagger PetStore](http://petstore.swagger.io/)
        - Definition: [JSON](https://editor.swagger.io/) downloaded to [sandbox.petstore](https://github.com/kjwenger/sandbox.petstore/README.md)

## Part 1: [Setting up C++ Development](doc/part/01.md)

## Part 2: [Setting up CppCMS Framework](doc/part/02.md)

## Part 3: [Setting up Cross-Compilation](doc/part/03.md)

## Part 4: [Setting up Testing](doc/part/04.md)

## Part 5: [Adding REST API Routes](doc/part/05.md)

## Part 6: [Adding Database](doc/part/06.md)

## Part 7: [Adding Object-relational mapping (ORM)](doc/part/07.md)

## Part 8: [Connecting REST API Handlers and ORM](doc/part/08.md)

## Part 99: C++ Developer's Digest

- Header: `*.hpp` `*.hxx`, `*.h`
    - Declarations:
        ```cpp
        // Single-line Comment
        int i; // Global Variable
        /*
         * Multi-line Comment
         */
        extern int n; // Out-of Module Scope Global Variable
        static int z; // Module Scope Global Variable
        class A; // Forward Declaration ... no size determination
        /**
         * Documenting Comment for e.g. doxygen
         */
        class B : { // Class Declaration
        public: // Public Visibility
            B(A & a); // Constructor Declaration ... no return value marks constructors
            ~B(); // Destructor Declaration ... tilde marks destructors
            B(const B & other) = delete; // Delete Copy Constructor: non-construction-copyable
            B & operator=(const B&) = delete; // Delete Asssignment Operator: non-copyable
         protected: // Protected Visibility ... only extending classes
            A & a; // Object Reference Field ... cannot be nullptr and must always be initialized
        };
        class C : public B { // Pubic Class Inheritance
        // Header-only Programming ... no source needed
        public:
            C(); { } // Implicit Constructor Definition
            C(const C & c) // Implicit Copy Constructor Definition
                : a(c.a) //  Field Initialization
                { }
            virtual ~C() { } // Implicit Virtual Destructor Definition ... automatically calls super-class destructors
        private: // Private Visibility ... only class itself
            A * a; // Object Pointer Field
        };
        namespace z {
            class D : protected 
        }
        ```
- Source: `*.cpp` `*.cxx`
    - Definitions
        ```cpp
        int i = 0; // Initialization/Definition of Global Variable
        class B : { // Class Declaration
        B::B(A & a) : a(a) { } // Constructor Definition ... double colon is scope operator
        B::~B() { } // Destructor Definition
        ```
- Classes
    - Abstract Classes
    - Multiple Inheritance
- Objects
- Templates
    ```cpp
    template <typename T> int toInt(const T & t) { return (int) t;} // Function Template
    template <> int toInt(const std::string & string) { return atoi(string.c_str()); } // Template Specialization
    int i = toInt(0.0F); // Implicit Template Instantiation
    template int toInt(const double & d) { return round(d);} // Explicit Template Instantiation
    template <class C> class Wrapper {
    public:
        Wrapper(C & c) : c(new C) { }
        ~Wrapper() { delete c; }
    private:
        C * c;
    }
    ```
- Lambdas