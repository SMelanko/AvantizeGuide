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
   
   __Naming__: Camel style. Shorthand format is also allowed to use.

## Source files
   
   ```
   // Good.
   Main.cpp
   Utils.h + Utils.cpp
   HttpServer.h + HttpServer.cpp
   FileManager.h + FileManager.cpp or FileMgr.h + FileMgr.cpp
   
   // Never ever.
   main.pp
   HTTPServer.h + HTTPServer.cpp
   ```

## Enums

   ``` cpp
   // Good.
   enum class Role
   {
      USER,
      ADMIN,
      SUPERUSER
   };
   
   // Also good.
   enum class RoundMode : uint16_t
   {
      ROUND_HALF_UP = 1,
      ROUND_HALF_DOWN,
      ROUND_BANKERS
   };
   
   // Not bad but prefer enum class variant.
   enum Color
   {
      RED,
      GREEN,
      BLUE
   };
   
   // Never ever.
   enum Color { RED, GREEN, BLUE };
   enum class Color { Red, Green, Blue };
   ```

## Statements

   * if - else if - else.
   
   ``` cpp
   // Good.   
   const auto role = GetRole();
   
   if (role == Role::USER) {
      // ...
   } else if (role == Role::ADMIN) {
      // ...
   } else {
      // ...
   }
   
   // Also good.
   if (ok) {
      Log("Transaction has been successfully processed");
   }
   
   // Never ever.
   if (ok) { Log("Transaction has been successfully processed"); }
   if (ok)
      Log("Transaction has been successfully processed");
   ```

   * switch.
   
   ``` cpp
   // Good.
   const auto role = GetRole();
   
   switch (role)
   {
      case Role::USER:
         // In case if one statement.
         break;

      case Role::ADMIN:
      {
         // In case if several statements.
         break;
      }

      default:
         // ...
         break;
   }
   ```
   
   * loops.
   
   ``` cpp
   // Good.
   for (size_t i = 0; i < v.size(); ++i) {
      // ...
   }
   
   while (condition) {
      // ...
   }
   
   do {
      // ...
   } while (condition);
   
   // Perfect.
   for (const auto& val : v) {
      // ...
   }
   
   // Like C++ God.
   std::for_each(std::begin(v), std::end(v), [](const auto& val) {
      // ...
   });
   ```

## Exceptions

   ``` cpp
   // Good.
   try {
      // ...
   } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
   } catch (...) {
      std::cerr << "Unhandled exception has been occurred.\n";
   }
  ```

## Functions

   ``` cpp
   // Good.
   //! Returns the product name.
   std::string GetProductName();
   
   using StringOpt = boost::optional<std::string>;
   //! Returns the name of user agent.
   std::string GetUserAgent(const StringOpt& uin = StringOpt{});
   ```
   
   __Rule of thumb__:
   
   * Put spaces between function parameters in declaration and usage.
   
   ``` cpp
   // Good.
   auto user = std::make_unique<User>("Jason", "Statham", 49);
   
   // Bad.
   auto user = std::make_unique<User>("Jason","Statham",49);
   ```
   
   * If a function has a lot of parameters - don't write all of them in one line or don't write each parameter in one line.
   
   ``` cpp
   // Good.
   // Declaration.
   User MakeUser(const std::string& name, const std::string& surname,
      const int age, const Gender gender, const std::vector<std::string>& hobbies);
   // Usage.
   const auto user = MakeUser("Jason", "Statham", 49, Gender::Male,
      { "Acting", "Cooking", "Dance", "Video game" });
      
   // Never ever.
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

   ``` cpp
   // Good.
   #define MAJOR_VERSION 1
   #define MINOR_VERSION 2
   #define PATCH_VERSION 34

   #define STR(s) #s
   #define XSTR(s) STR(s)
   #define APP_VERSION XSTR(MAJOR_VERSION) "." XSTR(MINOR_VERSION) "." XSTR(PATCH_VERSION)
   ```

## Namespaces

   ``` cpp
   // Good.
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
