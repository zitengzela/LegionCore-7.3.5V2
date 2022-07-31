cmake_minimum_required(VERSION 2.6)
project(protobuf_decompiler)

SET(PROTOBUF_SRC_ROOT_FOLDER ${CMAKE_SOURCE_DIR}/dep/protobuf)
# SET(PROTOBUF_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/dep/protobuf/src/)
SET(PROTOBUF_LIBRARY ${CMAKE_SOURCE_DIR}/dep/protobuf/src/)
SET(PROTOBUF_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/dep/protobuf/src/)
SET(PROTOBUF_IMPORT_DIRS ${CMAKE_SOURCE_DIR}/dep/protobuf/src/)

find_package(Protobuf)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
find_package(Boost 1.49 REQUIRED filesystem system)

include_directories(
    ${PROTOBUF_INCLUDE_DIRS}
    ${PROTOBUF_LIBRARY}
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/dep/protobuf
    ${CMAKE_SOURCE_DIR}/dep/protobuf/src/google
    ${CMAKE_SOURCE_DIR}/dep/protobuf/src/google/protobuf
    ${CMAKE_SOURCE_DIR}/dep/protobuf/src/google/protobuf/stubs
)

add_executable(protobuf_decompiler main.cpp)

target_link_libraries(protobuf_decompiler protobuf ${Boost_LIBRARIES})

install(TARGETS protobuf_decompiler RUNTIME DESTINATION bin)
