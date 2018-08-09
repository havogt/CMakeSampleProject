cmake_minimum_required(VERSION 3.10)
project(ProjectC VERSION 0.1)
enable_language(CXX)

find_package(ProjectB 0.1 REQUIRED)

add_executable(project_c
        src/main.cpp
        )

target_link_libraries(project_c
        ProjectB::project_b
        )
   