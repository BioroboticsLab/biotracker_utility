##############################################################
#### Biotracker: Utility
##############################################################

target_include_directories(${TN} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
    $<INSTALL_INTERFACE:${INSTALL_INCLUDEDIR}>
)

find_package(RF_Interfaces 0.1 REQUIRED)
target_link_libraries(${TN} BT_Interfaces)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Xml Network Widgets)
target_link_libraries (${TN} Qt5::Core Qt5::Gui Qt5::Xml Qt5::Network Qt5::Widgets)

set_target_properties(${TN} PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(${TN} PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON)
set_target_properties(${TN} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_sources(${TN}
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/settings/ParamNames.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/settings/Settings.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/settings/StringTranslator.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/settings/SystemCompatibilityCheck.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/settings/TrackedComponents/TrackedComponentFactory.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/settings/TrackedComponents/TrackedElement.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/settings/TrackedComponents/TrackedTrajectory.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/CvHelper.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/misc.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/stringTools.cpp"
)

set(${TN}_PUBLIC_HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/settings/Messages.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/ParamNames.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/Settings.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/StringTranslator.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/SystemCompatibilityCheck.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/TrackedComponents/TrackedComponentFactory.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/TrackedComponents/TrackedElement.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/TrackedComponents/TrackedTrajectory.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/CvHelper.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/Exceptions.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/misc.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/MutexWrapper.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/PanZoomState.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/platform.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/QtRaiiWrapper.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/ScreenHelper.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/singleton.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/stdext.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/stringTools.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/ImagePreProcessor.h"
    "${CMAKE_CURRENT_LIST_DIR}/settings/util/IImageProcessor.h"
)