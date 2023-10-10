cmake_minimum_required(VERSION 3.26)
project(Support_of_3D_curves_hierarchy)

set(CMAKE_CXX_STANDARD 17)

add_executable(Support_of_3D_curves_hierarchy
        src/main.cc
        src/model/figures.h
        src/model/figures.h
        src/model/figures.cc
        src/model/abstract_figure.h
        src/generator/generator.cc
        src/generator/generator.h)
