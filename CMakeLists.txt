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

source_group("thirdparties/mutils/Headers" FILES ${MUTILS_HEADERS})
source_group("thirdparties/mutils/Sources" FILES ${MUTILS_SRC})

# SFML
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
if (SFML_FOUND)
   include_directories(${SFML_INCLUDE_DIR})
   target_link_libraries(${LIB_NAME} ${SFML_LIBRARIES})
endif()
