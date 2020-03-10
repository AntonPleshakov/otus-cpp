cmake_minimum_required(VERSION 3.2)

project(otus_cpp VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_subdirectory(HelloWorld)

enable_testing()
