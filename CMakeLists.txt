cmake_minimum_required(VERSION 3.26)
project(stomfoolery CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON" FORCE)

add_library(stomfoolery INTERFACE)
target_include_directories(stomfoolery INTERFACE ./src)

add_library(String_Tomfoolery INTERFACE)
target_include_directories(String_Tomfoolery INTERFACE .)
