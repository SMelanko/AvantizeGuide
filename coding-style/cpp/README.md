# Avantize C++ Coding Style Guide

Here is a guide for C++ Coding Style.

## Defines

   __Naming__: Uppercase format plus underscore.
   
   ``` cpp
   #define MAJOR_VERSION 1
   #define MINOR_VERSION 2
   #define PATCH_VERSION 34

   #define STR(s) #s
   #define XSTR(s) STR(s)
   #define APP_VERSION \
      XSTR(MAJOR_VERSION) "." XSTR(MINOR_VERSION) "." XSTR(PATCH_VERSION)
   ```

