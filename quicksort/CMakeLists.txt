cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)
include_directories (..)
add_executable(quicksort_tests
    test/test_quicksort.cpp)

find_library(COMMON NAMES common PATHS "../common" NO_DEFAULT_PATH)
target_link_libraries (quicksort_tests LINK_PUBLIC ${COMMON})

enable_testing()
add_Test(NAME quicksortTest COMMAND quicksort_tests)
