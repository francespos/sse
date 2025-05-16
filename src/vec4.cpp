#include <sse/vec4.hpp>

namespace sse {
    vec4::vec4() {}

    vec4::vec4(float x, float y, float z, float w)
    : m_data(_mm_set_ps(w, z, y, x)) {}

    float& vec4::operator[](size_t pos) {
        return m_elems[pos];
    }

    float vec4::operator[](size_t pos) const {
        return m_elems[pos];
    }

    vec4 vec4::operator+(const vec4& other) const {
        vec4 ret;
        ret.m_data = _mm_add_ps(m_data, other.m_data);
        return ret;
    }

    vec4 vec4::operator-(const vec4& other) const {
        vec4 ret;
        ret.m_data = _mm_sub_ps(m_data, other.m_data);
        return ret;
    }

    vec4 vec4::operator*(float other) const {
        vec4 ret;

        auto factor = _mm_set_ps1(other);
        ret.m_data = _mm_mul_ps(m_data, factor);

        return ret;
    }

    vec4 vec4::operator/(float other) const {
        vec4 ret;

        auto divisor = _mm_set_ps1(other);
        ret.m_data = _mm_div_ps(m_data, divisor);

        return ret;
    }
}

sse::vec4 operator*(float lhs, const sse::vec4& rhs) {
    return rhs * lhs;
}