cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(tree CXX)

set(SRC_FILES
    include/node.h
    include/traversal.h
    src/node
    src/traversal
)

set(TREE_FILES
    src/tree
)

set(TEST_FILES
    src/node_test
    src/run_test
)

add_executable(tree ${SRC_FILES} ${TREE_FILES})
add_executable(tree_test ${SRC_FILES} ${TEST_FILES})
