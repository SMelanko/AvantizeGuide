# Avantize C++ Coding Style Guide

First of all look through some [examples](src).

- [C++ Coding Style](#c++-coding-style)
   - [Source files](#source-files)
   - [Enums](#enums)
   - [Statements](#statements)
   - [Exceptions](#exceptions)
   - [Functions](#functions)
   - [Defines](#defines)
   - [Namespaces](#namespaces)
   - [Classes](#classes)

## Source files

   __Naming__: Camel style. Shorthand format is also allowed to use.
   
   ```
   // GOOD.
   Main.cpp
   Utils.h + Utils.cpp
   HttpServer.h + HttpServer.cpp
   FileManager.h + FileManager.cpp or FileMgr.h + FileMgr.cpp
   
   // NEVER EVER.
   main.pp
   HTTPServer.h + HTTPServer.cpp
   ```

## Enums
   
   __Naming__: Camel style. Shorthand format is also allowed to use.
   
   ``` cpp
   // GOOD.
   enum class Role
   {
      USER,
      ADMIN,
      SUPER_USER
   };
   
   // NOT BAD.
   enum Color
   {
      RED,
      GREEN,
      BLUE
   };
   
   // BAD.
   enum Color { RED, GREEN, BLUE };
   ```

## Statements

   * if - else if - else.
   
   ``` cpp
   // GOOD.   
   auto role = GetRole();
   
   if (role == Role::USER) {
      // ...
   } else if (role == Role::ADMIN) {
      // ...
   } else {
      // ...
   }
   ```
   
   __Rule of thumb__: Always put a space after if, else if and before '('.
   
   * switch.
   
   ``` cpp
   // GOOD.
   auto role = GetRole();
   
   switch (role) {
      case Role::USER:
         // ...
         break;

      case Role::ADMIN:
         // ...
         break;

      default:
         // ...
         break;
   }
   ```
   
   * loops.
   
   ``` cpp
   // GOOD.
   for (size_t i = 0; i < v.size(); ++i) {
      // ...
   }
   
   while (condition) {
      // ...
   }
   
   do {
      // ...
   } while (condition);
   
   // PERFECT.
   for (const auto& val : v) {
      // ...
   }
   
   // GOD.
   std::for_each(std::begin(v), std::end(v), [](const auto& val) {
      // ...
   });
   ```
   
   __Rule of thumb__: Always put a space after for, do, while and before '(' or '{'.

## Exceptions

   ``` cpp
   // GOOD.
   try {
      // ...
   } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
   } catch (...) {
      std::cerr << "Unhandled exception has been occurred.\n";
   }
  ```
  
  __Rule of thumb__: Always catches exceptions by const reference.

## Functions

   __Naming__: Camel style. Shorthand format is also allowed to use.
   
   ``` cpp
   // GOOD.
   std::string GetProductName();
   
   using StringOpt = boost::optional<std::string>;
   std::string GetUserAgent(const StringOpt& uin = StringOpt{});
   ```
   
   __Rule of thumb__:
   
   * Put spaces between function parameters in declaration and usage.
   
   ``` cpp
   // GOOD.
   auto user = std::make_unique<User>("Jason", "Statham", 49);
   
   // BAD.
   auto user = std::make_unique<User>("Jason","Statham",49);
   ```
   
   * If a function has a lot of parameters - don't write all of them in one line or don't write each parameter in one line.
   
   ``` cpp
   // GOOD.
   // Declaration.
   User MakeUser(const std::string& name, const std::string& surname,
      const int age, const Gender gender, const std::vector<std::string>& hobbies);
   // Usage.
   const auto user = MakeUser("Jason", "Statham", 49, Gender::Male,
      { "Acting", "Cooking", "Dance", "Video game" });
      
   // BAD.
   void Foo(const Parameter1 p1, const Parameter2 p2, ...);
   void Foo(const Parameter1 p1,
      const Parameter2 p2,
      ...);
   void Foo(
      const Parameter1 p1,
      const Parameter2 p2,
      ...);
   ```

## Defines

   __Naming__: Uppercase format plus underscore.
   
   ``` cpp
   // GOOD.
   #define MAJOR_VERSION 1
   #define MINOR_VERSION 2
   #define PATCH_VERSION 34

   #define STR(s) #s
   #define XSTR(s) STR(s)
   #define APP_VERSION XSTR(MAJOR_VERSION) "." XSTR(MINOR_VERSION) "." XSTR(PATCH_VERSION)
   ```

## Namespaces

   ``` cpp
   // GOOD.
   namespace Sm { namespace Utils {
   
   // ...
   
   } } // namespace Sm::Utils
   ```

## Classes

   * Inheritance.

   ``` cpp
   //
   // Declaration of the C class.
   //
   
   class C
      : public B
      , private C
   {
      // ...
   };
   ```
   
   * Construction and destruction section.
   
   ``` cpp
      //
      // Construction and destruction.
      //
   public:
      //! Constructor.
      User() = default;
      //! Constructor.
      User(const std::string& name, const std::string& email,
         const std::string& pwd, const Role role = Role::USER);
      //! Destructor.
      ~User() noexcept = default;
      //! Move constructor.
      User(User&& user) noexcept = default;
      //! Move assignment operator.
      User& operator=(User&& user) noexcept = default;
      // ... Copy constructor and copy assignment operator.
   ```
   
   * Public interface section.
   
   ``` cpp
      //
      // Public interface.
      //
   public:
      //! Returns user's email.
      const std::string& GetEmail() const;
      //! Returns user's name.
      const std::string& GetName() const;
      // ...
   ```

   * Private or protected methods section.
   
   ``` cpp
      //
      // Private methods.
      //
   private:
      //! Installs drivers and helper DLLs to the system.
      void Install();
      //! Uninstalls drivers and helper DLLs from the system.
      void Uninstall();
      // ...
   ```
