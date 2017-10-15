cmake_minimum_required(VERSION 3.7)
project(Queue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Queue.h Linked_Queue.h Array_Based_Queue.h test.h)
add_executable(Queue ${SOURCE_FILES})

include_directories(../Common)