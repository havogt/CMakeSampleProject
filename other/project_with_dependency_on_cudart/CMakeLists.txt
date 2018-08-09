cmake_minimum_required(VERSION 3.9)
project(MyProject VERSION 1.0)
enable_language(CUDA)

find_library(CUDART_LIBRARY cudart ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})

add_executable(binary_linking_to_cudart my_cpp_file_using_cudart.cpp)
target_include_directories(binary_linking_to_cudart PRIVATE ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})
target_link_libraries(binary_linking_to_cudart ${CUDART_LIBRARY})
