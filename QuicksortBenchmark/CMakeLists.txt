cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)
include_directories (..)
add_executable(benchmark
    test/main.cpp)

find_library(COMMON NAMES common PATHS "../common" NO_DEFAULT_PATH)
target_link_libraries (benchmark LINK_PUBLIC ${COMMON})

enable_testing()
add_Test(NAME benchmark COMMAND benchmark)
