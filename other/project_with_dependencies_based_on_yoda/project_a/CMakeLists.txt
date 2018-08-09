cmake_minimum_required(VERSION 3.11)
project(ProjectA VERSION 0.1)
enable_language(CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(initializeYoda)

# I guess this should go into initializeYoda
list(APPEND CMAKE_MODULE_PATH "${YODA_SOURCE_DIR}/cmake")

# TODO check what it does
include(yodaInit)
yoda_init()

set(BUILD_SHARED_LIBS OFF) #TODO find the standard way for yoda!

yoda_report_result("Package summary" ${package_info})

# to make things complicated, first build an object library
yoda_add_library(
        NAME project_a
        OBJECT
        SOURCES
            src/private/project_a_private.cpp
            src/public/project_a_public.cpp
        )
# what is the benefit of the yoda_add_library for object libraries?

# TODO Would that be yoda-style:
target_compile_features(project_aObjects PRIVATE cxx_std_11)  
# in contrast to plain CMake the "Objects" is not so obvious

include(GNUInstallDirs)

yoda_create_library(
        TARGET ProjectA
        VERSION ${PROJECT_VERSION}
        SOURCES
            empty_file.cpp # I guess we want to combine several objects without having to put a src
        PUBLIC_BUILD_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include # Should be specified on the object library, but not supported?
        PUBLIC_INSTALL_INCLUDES include
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}
        TARGET_NAMESPACE ProjectA::
        OBJECTS project_aObjects
)

        
# generate cmake version file and config and install
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/ProjectAConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAConfig.cmake
    INSTALL_DESTINATION cmake
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/
    )    
    
# what's the good way to install headers?
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/project_a DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} 
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
        )
