# Avantize CMake Coding Style Guide

Here is a guide describes the recommended coding style for CMake.

First of all look through [CMakeLists.txt](src/CMakeLists.txt).

Here are some rules we are sticking to.

1. All variable in uppercase format plus underscore, for example:

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
3. Function (macro) names and it's params in lower case plus underscore.

   ``` cmake
   function(edit_file filename)
      file(READ ${filename} OLD_FILE_CONTENT)
      string(REGEX REPLACE " STATIC " " SHARED " NEW_FILE_CONTENT "${OLD_FILE_CONTENT}")
      file(WRITE ${filename} "${NEW_FILE_CONTENT}")
   endfunction()
   ```
