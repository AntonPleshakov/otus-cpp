cmake_minimum_required(VERSION 3.2)

project(HelloWorldTests VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}_boost test_version_boost.cpp)
add_executable(${PROJECT_NAME}_google test_version_google.cpp)

set_target_properties(${PROJECT_NAME}_boost PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_include_directories(${PROJECT_NAME}_google PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}_boost
    ${Boost_LIBRARIES}
    HelloWorldVersion
)

target_link_libraries(${PROJECT_NAME}_google
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    HelloWorldVersion
)

target_compile_options(${PROJECT_NAME}_boost PRIVATE
    -Wall -Wextra -pedantic -Werror
)

target_compile_options(${PROJECT_NAME}_google PRIVATE
    -Wall -Wextra -pedantic -Werror
)

add_test(boost_test ${PROJECT_NAME}_boost)
add_test(google_test ${PROJECT_NAME}_google)
