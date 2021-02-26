cmake_minimum_required(VERSION 3.17)
project(LoFiStream)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Music_Stream_Cpp main.cpp src/code/Background.cpp src/code/Background.h)

target_link_libraries(Music_Stream_Cpp sfml-graphics sfml-audio)