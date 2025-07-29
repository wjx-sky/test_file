cmake_minimum_required(VERSION 3.8)

project(day_six_learning VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SOURCE_FILES src/main.cpp src/example.cpp )

add_executable(main_exe ${SOURCE_FILES})
target_include_directories(main_exe PRIVATE ${CMAKE_SOURCE_DIR}/include)
