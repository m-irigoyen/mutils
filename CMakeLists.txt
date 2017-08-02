#########
# MUTILS #
#########

cmake_minimum_required(VERSION 3.1)

SET(LIB_NAME "mutils")

set (CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

FILE(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
FILE(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/mutils/*.hpp)

add_library(${LIB_NAME} ${SRC} ${HEADERS})
