#include <sse/mat4.hpp>

namespace sse {
    mat4::mat4() {}

    mat4::mat4(float m11, float m12, float m13, float m14,
        float m21, float m22, float m23, float m24,
        float m31, float m32, float m33, float m34,
        float m41, float m42, float m43, float m44)
    : m_rows{vec4(m11, m12, m13, m14), vec4(m21, m22, m23, m24)
    , vec4(m31, m32, m33, m34), vec4(m41, m42, m43, m44)} {}

    vec4& mat4::operator[](size_t pos) {
        return m_rows[pos];
    }

    const vec4& mat4::operator[](size_t pos) const {
        return m_rows[pos];
    }

    bool mat4::operator==(const mat4& other) const {
        for (size_t i = 0; i < 4; ++i) {
            if (m_rows[i] != other.m_rows[i]) {
                return false;
            }
        }

        return true;
    }

    bool mat4::operator!=(const mat4& other) const {
        return !(*this == other);
    }

    mat4 mat4::operator+(const mat4& other) const {
        mat4 ret;

        for (size_t i = 0; i < 4; ++i) {
            ret.m_rows[i] = m_rows[i] + other.m_rows[i];
        }

        return ret;
    }

    mat4 mat4::operator-(const mat4& other) const {
        mat4 ret;

        for (size_t i = 0; i < 4; ++i) {
            ret.m_rows[i] = m_rows[i] - other.m_rows[i];
        }

        return ret;
    }

    vec4 mat4::operator*(const vec4& other) const {
        vec4 ret;

        for (size_t i = 0; i < 4; ++i) {
            ret[i] = m_rows[i].dot(other);
        }

        return ret;
    }

    mat4 mat4::operator*(float other) const {
        mat4 ret;

        for (size_t i = 0; i < 4; ++i) {
            ret.m_rows[i] = m_rows[i] * other;
        }

        return ret;
    }

    mat4 mat4::operator/(float other) const {
        mat4 ret;

        for (size_t i = 0; i < 4; ++i) {
            ret.m_rows[i] = m_rows[i] / other;
        }

        return ret;
    }

    mat4& mat4::operator+=(const mat4& other) {
        *this = *this + other;
        return *this;
    }

    mat4& mat4::operator-=(const mat4& other) {
        *this = *this - other;
        return *this;
    }

    mat4& mat4::operator*=(float other) {
        *this = *this * other;
        return *this;
    }

    mat4& mat4::operator/=(float other) {
        *this = *this / other;
        return *this;
    }
} 

sse::mat4 operator*(float lhs, const sse::mat4& rhs) {
    return rhs * lhs;
}