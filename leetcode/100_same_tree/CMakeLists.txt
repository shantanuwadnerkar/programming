cmake_minimum_required(VERSION 3.10)

project(100_same_tree)

set(SAME_TREE_INCLUDE binary_tree_node.h)
set(SAME_TREE_SRC same_tree.cpp)

add_executable(same_tree ${SAME_TREE_SRC} ${SAME_TREE_INCLUDE})





# Incomplete attempt.
# Attempt to use the binary_tree_node.h file from the folder in data_structures/cpp/binary_tree without copying it in 100_same_tree
# Source:
# http://mariobadr.com/creating-a-header-only-library-with-cmake.html
# https://stackoverflow.com/questions/39887352/how-to-create-a-cmake-header-only-library-that-depends-on-external-header-files
# https://stackoverflow.com/questions/13703647/how-to-properly-add-include-directories-with-cmake

# set(BINARY_TREE_NODE_DIR ../../data_structures/cpp/binary_tree)
# set(BINARY_TREE_NODE ${BINARY_TREE_NODE_DIR}/binary_tree_node.h)

# add_library(binary_tree_node SHARED ${BINARY_TREE_NODE})
# target_include_directories(binary_tree_node PRIVATE ${BINARY_TREE_NODE_DIR})
# add_executable(binary_tree same_tree.cpp ${BINARY_TREE_NODE})
# target_include_directories(binary_tree PRIVATE ${BINARY_TREE_NODE})


# add_library(binary_tree_node INTERFACE)
# target_include_directories(binary_tree_include INTERFACE ${BINARY_TREE_NODE_DIR})
