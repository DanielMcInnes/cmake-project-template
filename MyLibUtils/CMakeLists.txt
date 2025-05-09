cmake_minimum_required(VERSION 3.14)
project(MyLibUtils VERSION 1.0 LANGUAGES CXX)

add_library(MyLibUtils STATIC
    src/MyLibUtils.cpp
    include/MyLibUtils/MyLibUtils.h
)

target_include_directories(MyLibUtils PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(MyLibUtils::MyLibUtils ALIAS MyLibUtils)

include(GNUInstallDirs)

install(TARGETS MyLibUtils
    EXPORT MyLibUtilsExports
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT MyLibUtilsExports
    FILE MyLibUtilsTargets.cmake
    NAMESPACE MyLibUtils::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyLibUtils
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/MyLibUtilsConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/MyLibUtilsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/MyLibUtilsConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyLibUtils
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/MyLibUtilsConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/MyLibUtilsConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyLibUtils
)
