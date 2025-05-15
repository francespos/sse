add_library(sse STATIC vec4.cpp mat4.cpp)
target_include_directories(sse PUBLIC ../include)
set_property(TARGET sse PROPERTY CXX_STANDARD 14)