cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(ENV{TRAVIS_BUILD_NUMBER} 1)
endif()

project(otus_cpp VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

enable_testing()

add_subdirectory(HelloWorld)
