cmake_minimum_required(VERSION 3.29)
project(Macros LANGUAGES CXX)

add_library(Macros INTERFACE)

target_include_directories(Macros INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# test
if (CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    set(CMAKE_CXX_STANDARD 11)
    add_executable(MacrosTest test/test.cpp)

    target_link_libraries(MacrosTest PRIVATE Macros)
    target_compile_definitions(MacrosTest
            PRIVATE KANI_MACROS_USE_STRING_VIEW
            PRIVATE KANI_MACROS_USE_SHARED_MUTEX
    )
endif()
