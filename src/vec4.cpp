#include <sse/vec4.h>

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

    bool vec4::operator==(const vec4& other) const {
        auto cmp = _mm_cmpeq_ps(m_data, other.m_data);
        return _mm_movemask_ps(cmp) == 0xF;
    }

    bool vec4::operator!=(const vec4& other) const {
        return !(*this == other);
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

    vec4& vec4::operator+=(const vec4& other) {
        m_data = _mm_add_ps(m_data, other.m_data);
        return *this;
    }

    vec4& vec4::operator-=(const vec4& other) {
        m_data = _mm_sub_ps(m_data, other.m_data);
        return *this;
    }

    vec4& vec4::operator*=(float other) {
        auto factor = _mm_set_ps1(other);
        m_data = _mm_mul_ps(m_data, factor);
        return *this;
    }

    vec4& vec4::operator/=(float other) {
        auto divisor = _mm_set_ps1(other);
        m_data = _mm_div_ps(m_data, divisor);
        return *this;
    }

    float vec4::dot(const vec4& other) const {
        auto dp = _mm_dp_ps(m_data, other.m_data, 0xF1);
        return _mm_cvtss_f32(dp);    
    }
}

sse::vec4 operator*(float lhs, const sse::vec4& rhs) {
    return rhs * lhs;
}