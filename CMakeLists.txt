cmake_minimum_required(VERSION 3.24)
project(CWAPI_CPP_samples)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(CADWORK_VERSION 29)
set(CMAKE_PREFIX_PATH "C:/source/cadlib/3rdParty/v_30.0/Qt/x64/lib/cmake")
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

set(CW_WIN 1)

IF(CW_WIN)
    SET(CADLIB_DIR "C:/source/cadlib")
ENDIF()

INCLUDE_DIRECTORIES("${CADLIB_DIR}/v_${CADWORK_VERSION}.0/3d/CwAPI3D")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(CWAPI_CPP_samples SHARED
        main.cpp
        CwAPI3D_Plugin.h
        CMyDialog.cpp
        CMyDialog.h)

target_link_libraries(CWAPI_CPP_samples
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )




