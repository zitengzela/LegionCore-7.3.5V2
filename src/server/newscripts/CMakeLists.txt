# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Enable precompiled headers when using the GCC compiler.

macro(PrepareScripts2 name out)
  file(GLOB_RECURSE found
    ${name}/*.h
    ${name}/*.hpp
    ${name}/*.cpp
  )
  list(APPEND ${out} ${found})
  message(STATUS "  -> Prepared: ${name}")
endmacro(PrepareScripts2)

PrepareScripts2(BrawlersGuild PRIVATE_SOURCES)

if(SCRIPTS)
  PrepareScripts2(Draenor PRIVATE_SOURCES)
  PrepareScripts2(EasternKingdoms PRIVATE_SOURCES)
  PrepareScripts2(Legion PRIVATE_SOURCES)
  PrepareScripts2(Outland PRIVATE_SOURCES)
  PrepareScripts2(Pandaria PRIVATE_SOURCES)
  PrepareScripts2(Scenario PRIVATE_SOURCES)
  PrepareScripts2(Maelstrom PRIVATE_SOURCES)
endif()

message(STATUS "SCRIPT PREPARATION COMPLETE")
message("")

list(APPEND PRIVATE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/ScriptLoader2.h
  ${CMAKE_CURRENT_SOURCE_DIR}/ScriptLoader2.cpp)

if (USE_SCRIPTPCH)
  set(PRIVATE_PCH_HEADER PrecompiledHeaders/NewScriptPCH.h)
  set(PRIVATE_PCH_SOURCE PrecompiledHeaders/NewScriptPCH.cpp)
  if (MSVC)
    list(INSERT PRIVATE_SOURCES 0 PrecompiledHeaders/NewScriptPCH.cpp)
  endif (MSVC)
endif ()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_library(scripts2 STATIC
  ${PRIVATE_SOURCES}
)

target_include_directories(scripts2
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(scripts2
  PUBLIC
    game)

set_target_properties(scripts2
    PROPERTIES
      FOLDER
        "server")

# Generate precompiled header
if (USE_SCRIPTPCH)
  add_cxx_pch(scripts2 ${PRIVATE_PCH_HEADER} ${PRIVATE_PCH_SOURCE})
endif()
