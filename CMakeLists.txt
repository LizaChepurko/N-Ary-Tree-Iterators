# ID 211548268
# Mail: lizachep@gmail.com

cmake_minimum_required(VERSION 3.10)
project(TreeTest)

set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(TreeTest
    PreOrder.cpp
    PostOrder.cpp
    InOrder.cpp
    DFS.cpp
    BFS.cpp
    Heap.cpp
    test_tree.cpp
    test_dfs.cpp
    test_bfs.cpp
    test_heap.cpp
    test_preorder.cpp
    test_postorder.cpp
    test_inorder.cpp
    test_complex.cpp
    test_main.cpp
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link Google Test libraries
target_link_libraries(TreeTest ${GTEST_LIBRARIES} pthread)
