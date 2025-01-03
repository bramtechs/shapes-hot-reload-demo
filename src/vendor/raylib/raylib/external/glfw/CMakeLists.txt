cmake_minimum_required(VERSION 3.5)
project(glfw)

add_library(${PROJECT_NAME} STATIC
  src/context.c
  src/egl_context.c
  src/getopt.c
  src/getopt.h
  src/init.c
  src/input.c
  src/internal.h
  src/mappings.h
  src/monitor.c
  src/null_init.c
  src/null_joystick.c
  src/null_joystick.h
  src/null_monitor.c
  src/null_platform.h
  src/null_window.c
  src/osmesa_context.c
  src/platform.c
  src/platform.h
  src/stdint.h
  src/vulkan.c
  src/vulkan.h
  src/wgl_context.c
  src/win32_init.c
  src/win32_joystick.c
  src/win32_joystick.h
  src/win32_module.c
  src/win32_monitor.c
  src/win32_platform.h
  src/win32_thread.c
  src/win32_thread.h
  src/win32_time.c
  src/win32_time.h
  src/win32_window.c
  src/window.c
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  gdi32
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
  _GLFW_WIN32
  _CRT_SECURE_NO_WARNINGS
)

target_include_directories(${PROJECT_NAME} PUBLIC
  include
)
