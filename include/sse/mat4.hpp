#include "vec4.hpp"

namespace sse {
    class mat4 {
    public:
        mat4();
        
        mat4(float m11, float m12, float m13, float m14,
            float m21, float m22, float m23, float m24,
            float m31, float m32, float m33, float m34,
            float m41 ,float m42, float m43, float m44);

        vec4& operator[](size_t pos);
        const vec4& operator[](size_t pos) const;

        bool operator==(const mat4& other) const;
        bool operator!=(const mat4& other) const;
        
        mat4 operator+(const mat4& other) const;
        mat4 operator-(const mat4& other) const;
        vec4 operator*(const vec4& other) const;
        mat4 operator*(float other) const;
        mat4 operator/(float other) const;

        mat4& operator+=(const mat4& other);
        mat4& operator-=(const mat4& other);
        mat4& operator*=(float other);
        mat4& operator/=(float other);
    private:
       vec4 m_rows[4]; 
    };
}

sse::mat4 operator*=(float lhs, const sse::mat4& rhs);