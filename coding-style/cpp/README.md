# C++ Coding Style Guide

First of all look through some [examples](src).

- [C++ Coding Style](#c++-coding-style)
   - [Header And Source Files](#source-files)
   - [Enums](#enums)
   - [Statements](#statements)
   - [Exceptions](#exceptions)
   - [Functions](#functions)
   - [Defines](#defines)
   - [Namespaces](#namespaces)
   - [Classes Declaration](#classes-declaration)
   
   __Naming__: Camel style. Shorthand format is also allowed to use.

## Header And Source Files

   1. Header files should have the extension .h whereas source files - .cpp.
   
   2. A class should be declared in a header file and defined in a source file where the name of the files match the name of the class:

   ```
   // Good.
   Utils.h + Utils.cpp
   HttpServer.h + HttpServer.cpp
   FileManager.h + FileManager.cpp
   
   // Never ever!
   main.cpp
   HTTPServer.h + HTTPServer.cpp
   request_router.h + request_router.cpp
   ```

   3. All definitions should reside in source files:

   ``` cpp
   class Counter
   {
   public:
     int GetValue() const { return value_; } // No!
     ...

   private:
     int value_;
   };
   ```

   The header files should declare an interface, the source file should implement it.

   4. File content must be kept within 80 columns. 80 columns is a common dimension for editors, terminal emulators, printers and debuggers, and files that are shared between several people should keep within these constraints. It improves readability when unintentional line breaks are avoided when passing a file between programmers.

   5. Header files must contain an include guard.

   6. TODO: Include statements should be sorted and grouped. Leave an empty line between groups of include statements.

## Enums

   1. Enums should have the following form:

   ``` cpp
   // Good.
   enum class Role
   {
      User,
      Admin,
      Superuser
   };
   
   // Also good.
   enum class RoundMode : uint16_t
   {
      RoundHalfUp = 1,
      RoundHalfDown,
      RoundBankers
   };
   
   // Not bad but prefer enum class variant.
   enum Color
   {
      Red,
      Green,
      Blue
   };
   
   // Never ever!
   enum Color { RED, GREEN, BLUE };
   enum class Color { Red, Green, Blue };
   ```

## Statements

   1. If - else if - else should have the following form:
   
   ``` cpp
   // Good.
   const auto role = GetRole();
   
   if (role == Role::User)
   {
      // ...
   }
   else if (role == Role::Admin)
   {
      // ...
   }
   else
   {
      // ...
   }
   
   // Also good if statement has only 1 line of code.
   if (ok) {
      Log("Transaction has been successfully processed");
   }
   
   // In case if statement has more than 1 line of code.
   if (!ok)
   {
      Log("Failed to save transaction");
      BOOST_THROW_EXCEPTION(std::runtime_error{ "Failed to save transaction" });
   }
   
   // Never ever!
   if (ok) { Log("Transaction has been successfully processed"); }
   if (ok) Log("Transaction has been successfully processed");
   if (ok)
      Log("Transaction has been successfully processed");
   ```

   2. Complex conditional expressions must be avoided. Introduce temporary boolean variables instead:

   ``` cpp
   // Good.
   const bool isFinished = (elementNo < 0) || (elementNo > maxElement);
   const bool isRepeatedEntry = elementNo == lastElement;
   if (isFinished || isRepeatedEntry) {
      // ...
   }

   // Not!
   if ((elementNo < 0) || (elementNo > maxElement) || elementNo == lastElement) {
      // ...
   }
   ```

   3. The conditional should be put on a separate line:

   ``` cpp
   // Good.
   if (isDone) {
      doCleanup();
   }

   // Bad!
   if (isDone) doCleanup();
   ```

   4. Switch should have the following form:
   
   ``` cpp
   // Good.
   const auto role = GetRole();
   
   switch (role)
   {
      case Role::User:
      {
         // In case if one statement.
         break;
      }
      case Role::Admin:
      {
         // In case if several statements.
         break;
      }
      default:
      {
         // ...
         break;
      }
   }
   ```
   
   5. Loops should have the following form:
   
   ``` cpp
   // Good.
   for (size_t i = 0; i < v.size(); ++i) {
      // In case if there is only 1 line here.
   }
   
   for (size_t i = 0; i < v.size(); ++i)
   {
      // In case if there are
      // 2 or more lines here.
   }
   
   // The same rules for while and do-while loops.
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

   6. Loop variables should be initialized immediately before the loop:

   ``` cpp
   // Good.
   bool isDone = false;
   while (!isDone) {
      // ...
   }

   // Not!
   bool isDone = false;
   // ...
   while (!isDone) {
      // ...
   }
   ```

   7. The form while(true) should be used for infinite loops.

## Exceptions

   1. A try-catch statement should have the following form:

   ``` cpp
   try
   {
      // It does not matter how many lines of code here - 
      // always the same format for try-catch blocks.
   }
   catch (const std::exception& e)
   {
      Log(e.what());
      std::cerr << e.what() << '\n';
   }
   catch (...)
   {
      std::cerr << "Unhandled exception has been occurred.\n";
   }
   ```

   2. Exception classes should be suffixed with Exception:

   ``` cpp
   class AccessException
   {
      // ...
   };
   ```

## Functions

   1. Names representing functions must be verbs and written in mixed case starting with upper case:
   
   ``` cpp
   //! Returns the product name.
   std::string GetProductName();
   
   using StringOpt = boost::optional<std::string>;

   //! Returns the name of user agent.
   std::string GetUserAgent(const StringOpt& uin = StringOpt{});
   ```
   
   2. Put spaces between function parameters in declaration and usage:
   
   ``` cpp
   // Good.
   auto user = std::make_unique<User>("Jason", "Statham", 49);
   
   // Bad!
   auto user = std::make_unique<User>("Jason","Statham",49);
   ```
   
   3. If a function has a lot of parameters - don't write all of them in one line or don't write each parameter in one line:
   
   ``` cpp
   // Good.
   // Declaration.
   User MakeUser(const std::string& name, const std::string& surname,
      const int age, const Gender gender, const std::vector<std::string>& hobbies);
   // Usage.
   const auto user = MakeUser("Jason", "Statham", 49, Gender::Male,
      { "Acting", "Cooking", "Dance", "Video game" });
      
   // Never ever!
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

   1. Defines must be all uppercase using underscore to separate words:
   
   ``` cpp
   #define MAJOR_VERSION 1
   #define MINOR_VERSION 2
   #define PATCH_VERSION 34

   #define STR(s) #s
   #define XSTR(s) STR(s)
   #define APP_VERSION XSTR(MAJOR_VERSION) "." XSTR(MINOR_VERSION) "." XSTR(PATCH_VERSION)
   ```

## Namespaces

   1. Names representing namespaces should be all lowercase:
   
   ``` cpp
   namespace sm
   {
   namespace utils
   {
   
   // ...
   
   } // namespace utils
   } // namespace sm
   ```

## Classes Declaration

   1. The parts of a class and inheritance list must be sorted public, protected and private:

   ``` cpp
   class C
      : public B
      , private A
   {
      // ...
   };
   ```
   
   2. Construction and destruction section:
   
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
   
   3. Public interface section:
   
   ``` cpp
      //
      // Public interface.
      //
   public:
      //! Returns user's email.
      const std::string& GetEmail() const noexcept;
      //! Returns user's name.
      const std::string& GetPassword() const noexcept;
      // ...
   ```

   4. Private or protected methods section:
   
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
   
   5. Private data member section:
   
   ``` cpp
      //
      // Private data members.
      //
   private:
      //! Redis client.
      std::shared_ptr<cpp_redis::redis_client> redisClient_;
   ```
   
   Private class variables should have underscore suffix.
   
   6. Inline section.
   
   ``` cpp
   class User
   {
      // ...
   };
   
   //
   // Inline implementation.
   //
   
   inline const std::string& User::GetEmail() const noexcept
   {
	   return email_;
   }

   inline const std::string& User::GetPassword() const noexcept
   {
	   return pwd_;
   }
   ```
