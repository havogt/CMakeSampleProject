cmake_minimum_required(VERSION 3.10)
project(ProjectB VERSION 0.1)
enable_language(CXX)

find_package(ProjectA 0.1 REQUIRED)

# build the library
add_library(project_b
        src/project_b.cpp
        )

target_link_libraries(project_b
        PRIVATE ProjectA::project_a
        )

target_include_directories(project_b
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
        
# generate cmake version file and config and install
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectBConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/ProjectBConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectBConfig.cmake
    INSTALL_DESTINATION cmake
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectBConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectBConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/
    )

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/project_b
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )

# install the library with targets
install(TARGETS project_b
    EXPORT project_b-export
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

install(EXPORT project_b-export
    FILE ProjectBTargets.cmake
    NAMESPACE ProjectB::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/
    )
   