cmake_minimum_required(VERSION 3.10)
project(ProjectA VERSION 0.1)
enable_language(CXX)

# build the library
add_library(project_a_header_only INTERFACE)

target_include_directories(project_a_header_only
        INTERFACE
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
        
# generate cmake version file and config and install
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAHeaderOnlyConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/ProjectAHeaderOnlyConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAHeaderOnlyConfig.cmake
    INSTALL_DESTINATION cmake
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAHeaderOnlyConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAHeaderOnlyConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/
    )    

# install the library with targets
install(TARGETS project_a_header_only
    EXPORT project_a_header_only-export
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
    
# what's the good way to install headers?
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/project_a_header_only DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} 
#        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
        )

install(EXPORT project_a_header_only-export
    FILE ProjectAHeaderOnlyTargets.cmake
    NAMESPACE ProjectAHeaderOnly::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/
    )
    