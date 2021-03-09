# Source:
# (also has best practices) https://stackoverflow.com/questions/2152077/is-it-possible-to-get-cmake-to-build-both-a-static-and-shared-version-of-the-sam
# https://cprieto.com/posts/2020/06/cmake-and-object-libraries.html

cmake_minimum_required(VERSION 3.10)

project(binary_tree)

set(BINARY_TREE_INCLUDE binary_tree_node.h binary_tree.h)
set(BINARY_TREE_SRC binary_tree.cpp)

# Two ways of compiling. To see the difference, independently compile
# both options and compare the console output

# 1. Compiles source files twice, for both static and shared libraries
# add_library(binary_tree_static
# 	STATIC
# 		${BINARY_TREE_INCLUDE}
# 		${BINARY_TREE_SRC}
# 	)

# add_library(binary_tree
# 	SHARED
# 		${BINARY_TREE_INCLUDE}
# 		${BINARY_TREE_SRC}
# 	)

# 2. Avoids duplicate compilation of object files
add_library(binary_tree_lib OBJECT ${BINARY_TREE_SRC} ${BINARY_TREE_INCLUDE})

set_property(TARGET binary_tree_lib PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(binary_tree_static
	STATIC
		$<TARGET_OBJECTS:binary_tree_lib>
	)

add_library(binary_tree
	SHARED
		$<TARGET_OBJECTS:binary_tree_lib>
	)

<<<<<<< Updated upstream:src/leetcode/111_minimum_depth_of_binary_tree/CMakeLists.txt
add_executable(maximum_depth maximum_depth_of_binary_tree.cpp)

target_link_libraries(maximum_depth binary_tree)
=======

add_executable(test_binary_tree test_binary_tree.cpp)
target_link_libraries(test_binary_tree binary_tree)
>>>>>>> Stashed changes:data_structures/cpp/binary_tree/CMakeLists.txt
