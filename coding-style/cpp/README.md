# Avantize C++ Coding Style Guide

Here is a guide for C++ Coding Style.

## Source files

   __Naming__: Camel style. Shorthand format is also allowed to use.
   
   ```
   // GOOD
   Main.cpp
   Utils.h + Utils.cpp
   HttpServer.h + HttpServer.cpp
   ErrorDialog.h + ErrorDialog.cpp or ErrDlg.h + ErrDlg.cpp
   FileManager.h + FileManager.cpp or FileMgr.h + FileMgr.cpp
   
   // NEVER EVER
   main.pp
   HTTPServer.h + HTTPServer.cpp
   ```

## Funtions

   __Naming__: Camel style. Shorthand format is also allowed to use.
   
   ```
   // GOOD
   std::string GetProductName();
   std::string GetAppName();
   ```
   
   __Rule of thumb__:
   
   * Put space between function parameters.
   
   ```
   // GOOD
   auto user = std::make_unique<User>("Jason", "Statham", 49);
   
   // BAD
   auto user = std::make_unique<User>("Jason","Statham",49);
   ```
   
   * If a function has a lot of parameters - don't write all of them in one line or don't write each parameter in one line.
   
   ```
   // Declaration.
   std::string MakeUser(const std::string& name, const std::string& surname, const int age, const Gender gender, const std::vector<std::string>& hobbies);
   
   // Usage.
   const auto user = MakeUser("Jason", "Statham", 49, Gender::Male,
      { "Acting", "Cooking", "Dance", "Video game" });
   ```

## Defines

   __Naming__: Uppercase format plus underscore.
   
   ``` cpp
   #define MAJOR_VERSION 1
   #define MINOR_VERSION 2
   #define PATCH_VERSION 34

   #define STR(s) #s
   #define XSTR(s) STR(s)
   #define APP_VERSION XSTR(MAJOR_VERSION) "." XSTR(MINOR_VERSION) "." XSTR(PATCH_VERSION)
   ```

