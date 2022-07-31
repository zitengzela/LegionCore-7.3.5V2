cmake_minimum_required(VERSION 3.0)
project(protoc_bnet)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# find_package(Protobuf REQUIRED)

set(SOURCE_FILES
  main.cpp
  BnetCodeGenerator.cpp
  BnetCodeGenerator.h
  BnetFileGenerator.cpp
  BnetFileGenerator.h
  BnetServiceGenerator.cpp
  BnetServiceGenerator.h
  method_options.pb.cc
  method_options.pb.h
  service_options.pb.cc
  service_options.pb.h
  )

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/dep/protobuf/src
)

add_executable(protoc_bnet ${SOURCE_FILES})

target_include_directories(protoc_bnet
  PUBLIC
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_SOURCE_DIR}/dep/protobuf/src
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(protoc_bnet protobuf ${Boost_LIBRARIES})

install(TARGETS protoc_bnet RUNTIME DESTINATION bin)

