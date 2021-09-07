cmake_minimum_required(VERSION 3.20)
project(GalaxyTest)

set(CMAKE_CXX_STANDARD 14)

include_directories(GalaxyTest/include)
include_directories(GalaxyTest/src)

add_executable(GalaxyTest
        GalaxyTest/include/flecs.c
        GalaxyTest/include/flecs.h
        GalaxyTest/include/flecs_os_api_stdcpp.cpp
        GalaxyTest/include/flecs_os_api_stdcpp.h
        GalaxyTest/src/GalaxyComponents.h
        GalaxyTest/src/GalaxyComponentConfig.h
        GalaxyTest/src/GalaxySystems.cpp
        GalaxyTest/src/GalaxySystems.h
        GalaxyTest/src/main.cpp)
