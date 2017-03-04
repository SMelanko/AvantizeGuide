# Avantize CMake Coding Style Guide

Here is a guide describes the recommended coding style for CMake.

Please look through [CMakeLists.txt](CMakeLists.txt).

Here are some rules we are sticking to.

1. All variable in uppercase format, for example:

   ``` cmake
   set(HEADERS ...)
   set(LIBRARY_PATH ...)
   ```

2. Use alphabetical order in the lists, for example:

   ``` cmake
   find_package(Boost REQUIRED COMPONENTS
      algorithm
      concept
      exception
      filesystem
      program_options
      serialization
      system
      )
   ```
