#ifndef SSE_VEC4_HPP
#define SSE_VEC4_HPP

#include <xmmintrin.h>

namespace sse
{
struct alignas(16) vec4
{
union
{
    __m128 m_data;
    
    struct
    {
        float x, y, z, w;
    };

    float m_elems[4];
};

vec4();
vec4(float x, float y, float z, float w);
};
} // namespace sse

#endif // ifndef SSE_VEC4_HPP