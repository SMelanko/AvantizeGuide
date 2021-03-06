cmake_minimum_required(VERSION 3.0.2)

project(ExampleProjectName CXX)

if (MSVC14 OR MSVC12) # Has the support we need.
	add_definitions(-D_SCL_SECURE_NO_WARNINGS)
	add_compile_options(/W4)
else ()
	include(CheckCXXCompilerFlag)
	CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
	CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
	if (COMPILER_SUPPORTS_CXX14)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wno-missing-braces")
	elseif (COMPILER_SUPPORTS_CXX11)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-missing-braces")
	else ()
		message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. "
			"Please use a different C++ compiler.")
	endif ()
endif ()

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED COMPONENTS
	exception
	filesystem
	program_options
	system
	)

set(HEADERS
	include/Example.h
	)

set(SOURCES
	src/Example.cpp
	src/Main.cpp
	)

include_directories(
	include
	${Boost_INCLUDE_DIRS}
	)

add_executable(${PROJECT_NAME}
	${HEADERS}
	${SOURCES}
	)

target_link_libraries(${PROJECT_NAME}
	${Boost_LIBRARIES}
	)
