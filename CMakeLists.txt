cmake_minimum_required(VERSION 3.19)
project(IntroductoryTask)

set(CMAKE_CXX_STANDARD 17)

add_executable(IntroductoryTask src/Application.cpp src/Parser.cpp src/Parser.h src/Logger.cpp src/Logger.h)