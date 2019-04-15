cmake_minimum_required(VERSION 3.13)
project(ArchitecturePrioj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(BranchHistoryPredictor main.cpp SmithCounter.cpp SmithCounter.h Simulator.cpp Simulator.h)