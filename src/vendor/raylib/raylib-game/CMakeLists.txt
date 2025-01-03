cmake_minimum_required(VERSION 3.5)
project(raylib-game)

add_executable(${PROJECT_NAME}
  game.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  raylib
)
