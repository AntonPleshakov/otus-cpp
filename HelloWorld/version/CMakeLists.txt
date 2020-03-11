cmake_minimum_required(VERSION 3.2)

project(HelloWorldVersion VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version_def.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version_def.h)

add_library(${PROJECT_NAME} version.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -pedantic -Werror
)
