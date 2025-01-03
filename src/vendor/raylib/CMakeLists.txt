cmake_minimum_required(VERSION 3.5)
project(raylib)

add_subdirectory(raylib-game)
add_subdirectory(raylib/external/glfw)

add_library(${PROJECT_NAME} STATIC
  raylib/raudio.c
  raylib/rcore.c
  raylib/raylib.h
  raylib/rmodels.c
  raylib/rshapes.c
  raylib/rtext.c
  raylib/rtextures.c
  raylib/utils.c
  raylib/utils.h
  raylib/rglfw.c
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  gdi32.lib winmm.lib glfw
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
  PLATFORM=PLATFORM_DESKTOP
  PLATFORM_DESKTOP
  _CRT_SECURE_NO_WARNINGS
)

target_include_directories(${PROJECT_NAME} PUBLIC
  raylib
  raylib/external
  raylib/external/glfw
)
