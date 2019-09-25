# Install script for directory: D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/out/build/x64-Debug/external/assimp-4.1.0/code/assimp-vc140-mtd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/anim.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/ai_assert.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/camera.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/color4.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/color4.inl"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/out/build/x64-Debug/external/assimp-4.1.0/code/../include/assimp/config.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/defs.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/Defines.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/cfileio.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/light.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/material.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/material.inl"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/matrix3x3.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/matrix3x3.inl"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/matrix4x4.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/matrix4x4.inl"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/mesh.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/postprocess.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/quaternion.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/quaternion.inl"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/scene.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/metadata.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/texture.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/types.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/vector2.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/vector2.inl"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/vector3.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/vector3.inl"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/version.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/cimport.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/importerdesc.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/Importer.hpp"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/DefaultLogger.hpp"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/ProgressHandler.hpp"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/IOStream.hpp"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/IOSystem.hpp"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/Logger.hpp"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/LogStream.hpp"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/NullLogger.hpp"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/cexport.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/Exporter.hpp"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/DefaultIOStream.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/DefaultIOSystem.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/SceneCombiner.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/Compiler/pushpack1.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/Compiler/poppack1.h"
    "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/external/assimp-4.1.0/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/out/build/x64-Debug/external/assimp-4.1.0/code/assimp-vc140-mtd.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "D:/Libraries/Documents/ogl-labs - Week 1/ogl-labs - Week 1/out/build/x64-Debug/external/assimp-4.1.0/code/assimp-vc140-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
endif()

