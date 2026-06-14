cmake_minimum_required(VERSION 3.16)

set(LIB_NAME "Log")
string(TOUPPER "${LIB_NAME}" LIB_NAME_UPPER)

project(${LIB_NAME} VERSION 0.1.1 LANGUAGES C)

# === Basic paths ===
set(LIBRARY_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Src)
set(EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Examples)
set(EXAMPLES_OUTPUT_DIR ${CMAKE_BINARY_DIR}/Examples)
file(GLOB_RECURSE LIBRARY_HEADERS ${LIBRARY_SRC_DIR}/*.h)

# === Options ===
option(${LIB_NAME_UPPER}_BUILD_EXAMPLES "Build example programs" OFF)

# === Header-only library ===
add_library(${LIB_NAME} INTERFACE)
add_library(${LIB_NAME}::HeaderOnly ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME} INTERFACE
    $<BUILD_INTERFACE:${LIBRARY_SRC_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_compile_definitions(${LIB_NAME} INTERFACE ${LIB_NAME_UPPER}_HEADER_ONLY)

message(STATUS "${LIB_NAME} is a header-only library")

# === Install headers and target ===
install(DIRECTORY ${LIBRARY_SRC_DIR}/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

install(TARGETS ${LIB_NAME}
    EXPORT ${LIB_NAME}Targets
)

# === Generate config files dynamically ===
include(CMakePackageConfigHelpers)
set(CONFIG_IN_CONTENT [=[
@PACKAGE_INIT@

include("${CMAKE_CURRENT_LIST_DIR}/${LIB_NAME}Targets.cmake")
]=])

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}Config.cmake.in" "${CONFIG_IN_CONTENT}")

configure_package_config_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}Config.cmake"
    INSTALL_DESTINATION lib/cmake/${LIB_NAME}
)

install(
    EXPORT ${LIB_NAME}Targets
    FILE ${LIB_NAME}Targets.cmake
    NAMESPACE ${LIB_NAME}::
    DESTINATION lib/cmake/${LIB_NAME}
)

install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}Config.cmake"
    DESTINATION lib/cmake/${LIB_NAME}
)

# === Optional: Build examples ===
if (${LIB_NAME_UPPER}_BUILD_EXAMPLES)
    file(MAKE_DIRECTORY ${EXAMPLES_OUTPUT_DIR})

    file(GLOB EXAMPLE_DIRS RELATIVE ${EXAMPLES_DIR} ${EXAMPLES_DIR}/*)
    foreach(EXAMPLE_NAME ${EXAMPLE_DIRS})
        set(EXAMPLE_PATH ${EXAMPLES_DIR}/${EXAMPLE_NAME})
        file(GLOB EXAMPLE_SOURCES ${EXAMPLE_PATH}/*.c)

        if(EXAMPLE_SOURCES)
            add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCES})
            target_include_directories(${EXAMPLE_NAME} PRIVATE ${LIBRARY_SRC_DIR})

            # Link header-only target (safe even for interface library)
            target_link_libraries(${EXAMPLE_NAME} PRIVATE ${LIB_NAME}::HeaderOnly)

            set_target_properties(${EXAMPLE_NAME} PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY ${EXAMPLES_OUTPUT_DIR})

            message(STATUS "Added example: ${EXAMPLE_NAME}")
        else()
            message(WARNING "No C sources found in example: ${EXAMPLE_NAME}")
        endif()
    endforeach()
endif()
