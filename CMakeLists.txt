cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

if(POLICY CMP0092)
    cmake_policy(SET CMP0092 NEW) # Don't add -W3 warning level by default.
endif()


file(READ "${CMAKE_CURRENT_SOURCE_DIR}/version.txt" VERSION_FILE_CONTENTS)
string(STRIP "${VERSION_FILE_CONTENTS}" VERSION_FILE_CONTENTS)
set(LM_VERSION "${VERSION_FILE_CONTENTS}" CACHE STRING "Set version name")
set(LM_PACKAGE "plugify-module-template" CACHE STRING "Set package name")
string(REPLACE "v" "" LM_VERSION "${LM_VERSION}")
string(REGEX REPLACE "[.+-]" ";" LM_VERSION_LIST ${LM_VERSION})
list(GET LM_VERSION_LIST 0 LM_VERSION_MAJOR)
list(GET LM_VERSION_LIST 1 LM_VERSION_MINOR)
list(GET LM_VERSION_LIST 2 LM_VERSION_PATCH)

project(plugify-module-template
        VERSION "${LM_VERSION_MAJOR}.${LM_VERSION_MINOR}.${LM_VERSION_PATCH}"
        DESCRIPTION "Template Language Module"
        HOMEPAGE_URL "https://github.com/untrustedmodders/plugify-module-template"
        LANGUAGES CXX
)
		
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE MATCHES "Debug|Devel|MinSizeRel|RelWithDebInfo|Release")
    message(STATUS "CMAKE_BUILD_TYPE not set, defaulting to Debug.")
    set(CMAKE_BUILD_TYPE Debug)
endif()

#
# Plugify
#
set(PLUGIFY_BUILD_SHARED_LIB ON CACHE INTERNAL "")
set(PLUGIFY_BUILD_JIT OFF CACHE INTERNAL "")
set(PLUGIFY_BUILD_ASSEMBLY OFF CACHE INTERNAL "")
set(PLUGIFY_BUILD_TESTS OFF CACHE INTERNAL "")
set(PLUGIFY_INTERFACE ON CACHE INTERNAL "")
set(PLUGIFY_DOWNLOADER OFF CACHE INTERNAL "")
add_subdirectory(external/plugify)

#
# Template Language Module for Plugify
#
file(GLOB_RECURSE LM_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${LM_SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE
    LM_IS_DEBUG=$<STREQUAL:${CMAKE_BUILD_TYPE},Debug>
)

target_link_libraries(${PROJECT_NAME} PRIVATE plugify::plugify)

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME} EXPORT_MACRO_NAME LM_EXPORT EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/module_export.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/exports)

if(APPLE)
    target_link_options(${PROJECT_NAME} PRIVATE "-Wl,-exported_symbols_list,${CMAKE_CURRENT_SOURCE_DIR}/sym/exported_symbols.lds")
elseif(UNIX)
    target_link_options(${PROJECT_NAME} PRIVATE "-Wl,--version-script,${CMAKE_CURRENT_SOURCE_DIR}/sym/version_script.lds")
endif()

configure_file(
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}.pmodule.in
    ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pmodule
)
