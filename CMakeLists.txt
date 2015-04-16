cmake_minimum_required (VERSION 2.6)
project (lab4)

set (lab3_VERSION_MAJOR 0)
set (lab3_VERSION_MINOR_1)

# TODO this HAS to be fixed or I am writting to your teacher ;)
# remove dependencies from other project files
# remove spaces form folders
# remove polish from source code
# remove using std
# format your code
# use tree structure
# use TDD
# use code review
# use h instead of hh (unless you know what you are doing)
# use namespaces
# why latex?
# do NOT keep binaries in github
# read about programming principles SOLID and GRASP
# don't break SRP
# NEVER ever include windows.h from non-ui!
# sched_setaffinity not present on OSX ... rats!

#include_directories("${PROJECT_SOURCE_DIR}/common"
#    "${PROJECT_SOURCE_DIR}/quicksort")

add_subdirectory(common)
add_subdirectory(quicksort)

enable_testing()


