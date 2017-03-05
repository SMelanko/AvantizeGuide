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

