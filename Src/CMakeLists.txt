##############################################################
#### Biotracker: Utility
##############################################################

target_include_directories(${TN} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
    $<INSTALL_INTERFACE:${INSTALL_INCLUDEDIR}>
)

find_package(BT_Interfaces 0.1 REQUIRED)
target_link_libraries(${TN} BT_Interfaces)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Xml Network Widgets)
target_link_libraries (${TN} Qt5::Core Qt5::Gui Qt5::Xml Qt5::Network Qt5::Widgets)
find_package(Boost REQUIRED system filesystem chrono timer)
target_link_libraries(${TN} 
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_CHRONO_LIBRARY}
  ${Boost_TIMER_LIBRARY}
)

set_target_properties(${TN} PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(${TN} PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON)
set_target_properties(${TN} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_sources(${TN}
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/TrackedComponents/TrackedComponentFactory.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/TrackedComponents/TrackedElement.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/TrackedComponents/TrackedTrajectory.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/util/misc.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/IConfig.cpp"
)

set(${TN}_PUBLIC_HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/TrackedComponents/TrackedComponentFactory.h"
    "${CMAKE_CURRENT_LIST_DIR}/TrackedComponents/TrackedElement.h"
    "${CMAKE_CURRENT_LIST_DIR}/TrackedComponents/TrackedTrajectory.h"
    "${CMAKE_CURRENT_LIST_DIR}/util/misc.h"
    "${CMAKE_CURRENT_LIST_DIR}/util/singleton.h"
    "${CMAKE_CURRENT_LIST_DIR}/util/ImagePreProcessor.h"
    "${CMAKE_CURRENT_LIST_DIR}/util/IImageProcessor.h"
    "${CMAKE_CURRENT_LIST_DIR}/IConfig.h"
)