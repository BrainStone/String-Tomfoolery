cmake_minimum_required(VERSION 3.26)
project(String_Tomfoolery)

set(CMAKE_CXX_STANDARD 23)

add_library(String_Tomfoolery INTERFACE)
target_include_directories(String_Tomfoolery INTERFACE .)
