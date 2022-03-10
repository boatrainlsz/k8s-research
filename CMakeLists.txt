cmake_minimum_required(VERSION 3.21)
project(ebpf_research)

set(CMAKE_CXX_STANDARD 14)

add_executable(k8s-research ns.cpp)
