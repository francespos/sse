add_library(sse STATIC vec4.cpp mat4.cpp)
target_include_directories(sse PUBLIC ../include)
set_property(TARGET sse PROPERTY CXX_STANDARD 14)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(sse PUBLIC -msse)
endif()