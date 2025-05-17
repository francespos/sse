enable_testing()

add_executable(vec4_test vec4_test.cpp)

target_link_libraries(vec4_test PRIVATE sse)
set_property(TARGET vec4_test PROPERTY CXX_STANDARD 14)

add_test(NAME Vec4Test COMMAND vec4_test)

add_executable(mat4_test mat4_test.cpp)

target_link_libraries(mat4_test PRIVATE sse)
set_property(TARGET mat4_test PROPERTY CXX_STANDARD 14)

add_test(NAME Mat4Test COMMAND mat4_test)