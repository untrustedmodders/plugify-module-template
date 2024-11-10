cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

if(POLICY CMP0092)
    cmake_policy(SET CMP0092 NEW) # Don't add -W3 warning level by default.
endif()


project(plugify-module-template VERSION 1.0.0.0  DESCRIPTION "Template Language Module" HOMEPAGE_URL "https://github.com/untrustedmodders/plugify-module-template" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# Plugify
#
set(PLUGIFY_BUILD_SHARED_LIB ON CACHE INTERNAL "")
set(PLUGIFY_BUILD_FUNCTION OFF CACHE INTERNAL "")
add_subdirectory(external/plugify)

#
# Go Language Module for Plugify
#
set(LM_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/module.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/module.cpp")
add_library(${PROJECT_NAME} SHARED ${LM_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE plugify::plugify)

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME} EXPORT_MACRO_NAME LM_EXPORT EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/module_export.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/exports)

if(APPLE)
	target_link_options(${PROJECT_NAME} PRIVATE "-Wl,-exported_symbols_list,${CMAKE_CURRENT_SOURCE_DIR}/sym/exported_symbols.lds")
elseif(UNIX)
	target_link_options(${PROJECT_NAME} PRIVATE "-Wl,--version-script,${CMAKE_CURRENT_SOURCE_DIR}/sym/version_script.lds")
endif()

set(LM_VERSION "${CMAKE_PROJECT_VERSION}")
set(LM_PACKAGE "${PROJECT_NAME}")

configure_file(
	${CMAKE_SOURCE_DIR}/${PROJECT_NAME}.pmodule.in
	${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pmodule
)
