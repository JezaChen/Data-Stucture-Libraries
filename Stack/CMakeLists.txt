cmake_minimum_required(VERSION 3.7)
project(Stack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Stack_common.h Array_Based_Stack.h Linked_Stack.h)
add_executable(Stack ${SOURCE_FILES})