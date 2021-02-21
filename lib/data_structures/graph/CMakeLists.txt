# Source:
# (also has best practices) https://stackoverflow.com/questions/2152077/is-it-possible-to-get-cmake-to-build-both-a-static-and-shared-version-of-the-sam
# https://cprieto.com/posts/2020/06/cmake-and-object-libraries.html

cmake_minimum_required(VERSION 3.10)

project(graph)

set(GRAPH_INCLUDE graph.h)
set(GRAPH_SRC graph.cpp)

set(DIJKSTRA_SRC dijkstra.cpp)
set(GRAPH_TEST_SRC test_graph.cpp)

# Two ways of compiling. To see the difference, independently compile
# both options and compare the console output

# 1. Compiles source files twice, for both static and shared libraries
# Check binary_tree for this method.

# 2. Avoids duplicate compilation of object files
add_library(graph_lib OBJECT ${GRAPH_SRC} ${GRAPH_INCLUDE})

set_property(TARGET graph_lib PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(graph_static
	STATIC
		$<TARGET_OBJECTS:graph_lib>
	)

add_library(graph
	SHARED
		$<TARGET_OBJECTS:graph_lib>
	)

add_executable(test_graph ${GRAPH_TEST_SRC})
target_link_libraries(test_graph graph)

add_executable(dijkstra ${DIJKSTRA_SRC})
target_link_libraries(dijkstra graph)
