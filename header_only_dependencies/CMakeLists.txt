cmake_minimum_required(VERSION 3.12.4)
project(test_header_only_dep LANGUAGES CXX)

add_subdirectory(header_only_lib)
add_subdirectory(src)
