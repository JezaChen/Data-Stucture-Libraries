cmake_minimum_required(VERSION 3.7)
project(Stack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Stack_common.h Array_Based_Stack.h Array_Based_Stack.cpp Linked_Stack.h LinkStack.cpp)
add_executable(Stack ${SOURCE_FILES})