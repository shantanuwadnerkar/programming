# Source:
# (also has best practices) https://stackoverflow.com/questions/2152077/is-it-possible-to-get-cmake-to-build-both-a-static-and-shared-version-of-the-sam

cmake_minimum_required(VERSION 3.10)

project(bst)

# TODO: add option for testing
set(${PROJECT_NAME}_SRC src/binary_tree.cpp)

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

# add_executable(test_binary_tree test_binary_tree.cpp)

# target_link_libraries(test_binary_tree binary_tree)


# 2. Avoids duplicate compilation of object files
add_library(${PROJECT_NAME}_obj OBJECT ${${PROJECT_NAME}_SRC})

set_property(TARGET ${PROJECT_NAME}_obj PROPERTY POSITION_INDEPENDENT_CODE 1)

target_include_directories(${PROJECT_NAME}_obj PUBLIC include)

# Static and Dynamic libraries
add_library(${PROJECT_NAME}_static
	STATIC
		$<TARGET_OBJECTS:${PROJECT_NAME}_obj>
	)

add_library(${PROJECT_NAME}
	SHARED
		$<TARGET_OBJECTS:${PROJECT_NAME}_obj>
	)

# Include directories to the static and dyanmic libraries
target_include_directories(${PROJECT_NAME}_static PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Add testing
if(BUILD_TEST)
	enable_testing()

	add_executable(test_${PROJECT_NAME} test/test_bst.cpp)

	target_link_libraries(test_${PROJECT_NAME} PUBLIC ${PROJECT_NAME})
endif(BUILD_TEST)

