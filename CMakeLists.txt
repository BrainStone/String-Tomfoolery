cmake_minimum_required(VERSION 3.22)
project(stomfoolery CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON" FORCE)

add_library(stomfoolery INTERFACE)
target_include_directories(stomfoolery INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")

###############################################################################
## testing ####################################################################
###############################################################################

enable_testing()
include(GoogleTest)
add_subdirectory(test)
