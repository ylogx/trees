cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(tree CXX)

add_executable(tree include/node.h include/traversal.h src/node src/traversal)
