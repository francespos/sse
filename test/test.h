#pragma once

#include <iostream>
#include <sse/mat4.h>

std::ostream& operator<<(std::ostream& out, const sse::vec4& v);
std::ostream& operator<<(std::ostream& out, const sse::mat4& m);