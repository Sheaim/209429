cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(common logger.cpp)
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test)
add_executable(common_tests
    logger.cpp
    test/test_logger.cpp)

enable_testing()
add_Test(NAME commonTest COMMAND common_tests)
