cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(tree CXX)

set(SRC_FILES
    include/node.h
    include/traversal.h
    src/node
    src/node_test
    src/traversal
)
add_executable(tree ${SRC_FILES})
