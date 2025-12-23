cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(makima-bot VERSION 0.0.1 DESCRIPTION "A discord bot"
    LANGUAGES CXX)

include(cmake/CPM.cmake)

CPMAddPackage("gh:xiph/ogg#v1.3.6")
CPMAddPackage(
    NAME DPP
    GITHUB_REPOSITORY brainboxdotcc/DPP
    OPTIONS "DPP_BUILD_TEST OFF"
    VERSION 10.1.3
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/${DPP_BINARY_DIR}/library/Debug/dpp.lib
    ogg
)
target_include_directories(${PROJECT_NAME} PRIVATE ${DPP_SOURCE_DIR}/include
    ${DPP_SOURCE_DIR}/win32/include
    ogg
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDART 17
    CXX_STANDART_REQUIRED ON
    CXX_EXTENSIONS OFF
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)
