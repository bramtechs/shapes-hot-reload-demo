cmake_minimum_required(VERSION 3.12)
project(shapes-hot-reload)

add_subdirectory(src/vendor/raylib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME}
  src/file_reader.hh
  src/file_reloader.hh
  src/file_reloader.cc
  src/local_file_reader.cc
  src/local_file_reader.hh
  src/shape.hh
  src/rectangle_shape.hh
  src/rectangle_shape.cc
  src/circle_shape.hh
  src/circle_shape.cc
  src/shape_importer.cc
  src/shape_importer_error.hh
  src/shape_importer_state.hh
  src/shape_importer_closed_state.cc
  src/shape_importer_open_state.cc
  src/demo.cc
)

target_include_directories(${PROJECT_NAME} PRIVATE
  src/vendor
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  raylib
)

if (WIN32)
  # change default working directory in Visual Studio to repository root.
  set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
  # change default starting project in Visual Studio
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT shapes-hot-reload)
endif()
