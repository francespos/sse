#include "test.h"

std::ostream& operator<<(std::ostream& out, const sse::vec4& v) {
    out << "[ ";

    for (size_t i = 0; i < 4; ++i) {
        out << v[i] << " ";
    }

    out << "]";
    return out;
}

std::ostream& operator<<(std::ostream& out, const sse::mat4& m) {
    for (size_t i = 0; i < 4; ++i) {
        out << "[ ";

        for (size_t j = 0; j < 4; ++j) {
            out << m[i][j] << " ";
        }

        out << "]\n";
    }

    return out;
}