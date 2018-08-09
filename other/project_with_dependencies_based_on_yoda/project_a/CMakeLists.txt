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
#yoda_add_library(
#        NAME project_a_objects
#        OBJECT
#        SOURCES
#            src/private/project_a_private.cpp
#            src/public/project_a_public.cpp
#        )

include(GNUInstallDirs)

yoda_create_library(
        TARGET project_a
        VERSION ${PROJECT_VERSION}
        SOURCES
            src/private/project_a_private.cpp
            src/public/project_a_public.cpp
        PUBLIC_BUILD_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include # doesn't make much sense at this point I guess
        PUBLIC_INSTALL_INCLUDES include
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}
        TARGET_NAMESPACE ProjectA::
       # DEPENDS project_a_objectsObjects
)


#add_library(project_a_objects OBJECT 
#        src/private/project_a_private.cpp
#        src/public/project_a_public.cpp
#        )

#target_include_directories(project_a_objects
#        PUBLIC
#            $<INSTALL_INTERFACE:include>
#            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#        PRIVATE
#            ${CMAKE_CURRENT_SOURCE_DIR}/src
#        )

# Is it possible with yoda?
#target_compile_features(project_a_objectsObjects PRIVATE cxx_std_11)  
        
# build the library
#add_library(project_a)
#target_link_libraries(project_a PUBLIC project_a_objects)

# generate cmake version file and config and install
#include(CMakePackageConfigHelpers)
#write_basic_package_version_file(
#    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAConfigVersion.cmake
#    VERSION ${PROJECT_VERSION}
#    COMPATIBILITY AnyNewerVersion
#)
#
#configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/ProjectAConfig.cmake.in
#    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAConfig.cmake
#    INSTALL_DESTINATION cmake
#)
#
#install(FILES
#    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAConfig.cmake
#    ${CMAKE_CURRENT_BINARY_DIR}/ProjectAConfigVersion.cmake
#    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/
#    )    
#
# install the library with targets
#install(TARGETS project_a project_a_objects
#    EXPORT project_a-export
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    )
#    
# what's the good way to install headers?
#install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/project_a DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} 
#        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
#        )
#
#install(EXPORT project_a-export
#    FILE ProjectATargets.cmake
#    NAMESPACE ProjectA::
#    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/
#    )
    