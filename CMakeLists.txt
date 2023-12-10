cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(makima-bot VERSION 0.0.1 DESCRIPTION "A discord bot"
	LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(DPP REQUIRED)

add_executable(${PROJECT_NAME}
	src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	${DPP_LIB}
)

target_include_directories(${PROJECT_NAME} PRIVATE
	${DPP_INCLUDE}
)

include_directories(${DPP_INCLUDE})

set_target_properties(${PROJECT_NAME} PROPERTIES
CXX_STANDART 17
CXX_STANDART_REQUIRED ON
)
