##############################################################
#### Biotracker: Utility
##############################################################
set(target ${PROJECT_NAME})
add_library(${target} STATIC)

if( CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR )
    find_package(biotracker-interfaces REQUIRED)
endif()
target_link_libraries(${target} biotracker-interfaces)

find_package(Boost REQUIRED COMPONENTS system filesystem chrono timer)
target_link_libraries(${target} Boost::headers Boost::system Boost::filesystem Boost::chrono Boost::timer)

install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME}Targets
    RUNTIME DESTINATION "${INSTALL_BINDIR}"
    ARCHIVE DESTINATION "${INSTALL_LIBDIR}"
)

target_include_directories(${target} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
    $<INSTALL_INTERFACE:${INSTALL_INCLUDEDIR}>
)

set_target_properties(${target} PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(${target} PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON)
set_target_properties(${target} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_sources(${target}
PRIVATE
    "Utility/TrackedComponents/TrackedComponentFactory.cpp"
    "Utility/TrackedComponents/TrackedElement.cpp"
    "Utility/TrackedComponents/TrackedTrajectory.cpp"
    "Utility/misc.cpp"
    "Utility/IConfig.cpp"
)

install_headers(
    HEADERS
    "Utility/TrackedComponents/TrackedComponentFactory.h"
    "Utility/TrackedComponents/TrackedElement.h"
    "Utility/TrackedComponents/TrackedTrajectory.h"
    "Utility/misc.h"
    "Utility/IConfig.h"
    DESTINATION "${INSTALL_INCLUDEDIR}"
)