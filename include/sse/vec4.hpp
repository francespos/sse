#pragma once

#include <xmmintrin.h>
#include <cstddef>

namespace sse {
    struct alignas(16) vec4 {
        union {
            __m128 m_data;
            
            struct {
                float x, y, z, w;
            };

            float m_elems[4];
        };

        vec4();
        vec4(float x, float y, float z, float w);

        float& operator[](size_t pos);
        float operator[](size_t pos) const;

        vec4 operator+(const vec4& other) const;
        vec4 operator-(const vec4& other) const;
        vec4 operator*(float other) const;
        vec4 operator/(float other) const;
    };
}

sse::vec4 operator*(float lhs, const sse::vec4& rhs);