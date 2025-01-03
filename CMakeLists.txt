cmake_minimum_required(VERSION 3.12)
project(file-reloader-observer)

add_subdirectory(src/vendor/raylib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME}
  src/file_reader.hh
  src/file_reloader.hh
  src/file_reloader.cc
  src/local_file_reader.cc
  src/local_file_reader.hh
  src/demo.cc
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  raylib
)
