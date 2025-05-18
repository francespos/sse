#pragma once

#include <iostream>
#include <sse/mat4.hpp>

std::ostream& operator<<(std::ostream& out, const sse::vec4& v);
std::ostream& operator<<(std::ostream& out, sse::mat4& m);