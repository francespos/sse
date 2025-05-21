cmake_minimum_required(VERSION 3.10)

project(Sse)

add_subdirectory(src)

if(DEFINED SSE_TEST)
    add_subdirectory(test)
endif()