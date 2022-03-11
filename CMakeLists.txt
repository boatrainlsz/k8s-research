cmake_minimum_required(VERSION 3.21)
project(k8s-research)

set(CMAKE_CXX_STANDARD 14)

add_executable(ns demo/ns.cpp)
add_executable(setns demo/geektime07/setns.cpp)
