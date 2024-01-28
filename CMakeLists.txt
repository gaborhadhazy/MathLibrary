cmake_minimum_required(VERSION 3.22)
project(dadoy)

set(CMAKE_CXX_STANDARD 17)

add_executable(dadoy main.cc
        Include/Math.h
        src/BaseMath.cc
        src/BaseMath.cc
        src/LinearEquation.cc
        src/utils/Lexer.cc

        )
