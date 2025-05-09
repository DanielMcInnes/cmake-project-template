cmake_minimum_required(VERSION 3.14)
project(MyLibA VERSION 1.0 LANGUAGES CXX)

find_package(MyLibUtils REQUIRED)

add_library(MyLibA STATIC
    src/MyLibA.cpp
    include/MyLibA/MyLibA.h
)

target_include_directories(MyLibA PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(MyLibA PUBLIC MyLibUtils::MyLibUtils)

add_library(MyLibA::MyLibA ALIAS MyLibA)

include(GNUInstallDirs)

install(TARGETS MyLibA
    EXPORT MyLibAExports
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT MyLibAExports
    FILE MyLibATargets.cmake
    NAMESPACE MyLibA::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyLibA
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/MyLibAConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/MyLibAConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/MyLibAConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyLibA
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/MyLibAConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/MyLibAConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyLibA
)
