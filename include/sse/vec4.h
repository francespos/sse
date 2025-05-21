#pragma once

#include <smmintrin.h>
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

        bool operator==(const vec4& other) const;
        bool operator!=(const vec4& other) const;

        vec4 operator+(const vec4& other) const;
        vec4 operator-(const vec4& other) const;
        vec4 operator*(float other) const;
        vec4 operator/(float other) const;

        vec4& operator+=(const vec4& other);
        vec4& operator-=(const vec4& other);
        vec4& operator*=(float other);
        vec4& operator/=(float other);

        float dot(const vec4& other) const;
    };
}

sse::vec4 operator*(float lhs, const sse::vec4& rhs);