#include <sse/vec4.hpp>

namespace sse
{
vec4::vec4() 
{
}

vec4::vec4(float x, float y, float z, float w)
: m_data(_mm_set_ps(w, z, y, x))
{
}
}; // namespace sse