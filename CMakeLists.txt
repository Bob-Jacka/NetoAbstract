cmake_minimum_required(VERSION 3.31)
project(NetoAbstract)

set(CMAKE_CXX_STANDARD 20)

add_executable(NetoAbstract
        firstTask/main.cpp
        #secondTask/main.cpp

        libio.hpp
        CityInfo.cpp
        CityInfo.hpp
        HelperData.hpp
)
