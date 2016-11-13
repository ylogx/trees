cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(tree CXX)

enable_language(C CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")

include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

#include_directories(
    #${PROJECT_SOURCE_DIR}/src
    #)

set(NODE_SRC_FILES
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

add_library(node ${NODE_SRC_FILES})

add_executable(tree ${TREE_FILES})
add_dependencies(tree node)
target_link_libraries(tree node)

add_executable(unit_tests ${SRC_FILES} ${TEST_FILES})
add_dependencies(unit_tests googletest)
target_link_libraries(unit_tests node googletest pthread)

include(CTest)
enable_testing()

add_test(unit ${PROJECT_BINARY_DIR}/unit_tests)
