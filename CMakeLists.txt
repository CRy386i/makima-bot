cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(makima-bot VERSION 0.0.1 DESCRIPTION "A discord bot"
    LANGUAGES CXX)

include(cmake/CPM.cmake)

CPMAddPackage(
    NAME DPP
    GITHUB_REPOSITORY brainboxdotcc/DPP
    VERSION 10.1.3
)

if(DPP_ADDED)
    # DPP has lack with question like "where's my headers?"
    add_library(DPP INTERFACE)

    target_include_directories(DPP SYSTEM INTERFACE ${DPP_SOURCE_DIR}/include)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE DPP)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDART 17
    CXX_STANDART_REQUIRED ON
    CXX_EXTENSIONS OFF
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)
