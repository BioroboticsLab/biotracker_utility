cmake_minimum_required(VERSION 3.15)

exec_program("git" ${CMAKE_CURRENT_SOURCE_DIR} ARGS "describe --dirty --always --exclude '*'" OUTPUT_VARIABLE SOURCE_VERSION)

project(biotracker-utility
    LANGUAGES CXX
)

include(GNUInstallDirs)

set(INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR} CACHE PATH "Installation directory for executables")
set(INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR} CACHE PATH "Installation directory for libraries")
set(INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME} CACHE PATH "Installation directory for header files")
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME} CACHE STRING "Installation directory for cmake configuration files")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(Headers)

add_subdirectory(Src)

export(
    TARGETS
        ${PROJECT_NAME}
    FILE "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake"
)

install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${SOURCE_VERSION}
    COMPATIBILITY ExactVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Modules/${PROJECT_NAME})
configure_file(cmake/TrackerPlugin.cmake Modules/${PROJECT_NAME} COPYONLY)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Modules DESTINATION "${INSTALL_CONFIGDIR}")

set(CPACK_GENERATOR "TXZ")
set(CPACK_PACKAGE_VERSION "${SOURCE_VERSION}")

include(CPack)
