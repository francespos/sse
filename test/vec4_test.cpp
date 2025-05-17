#include <iostream>
#include <sse/vec4.hpp>

std::ostream& operator<<(std::ostream& out, const sse::vec4& v) {
    out << "[ ";

    for (size_t i = 0; i < 4; ++i) {
        out << v[i] << " ";
    }

    out << "]";
    return out;
}

int main() {
    sse::vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
    std::cout << v << "\n\n";

    sse::vec4 v1 = v;
    sse::vec4 v2(2.0f, 3.0f, 4.0f, 5.0f);

    std::cout << "v1 + v2 = " << v1 + v2 << "\n";
    std::cout << "v1 - v2 = " << v1 - v2 << "\n";
    std::cout << "4.0f * v1 = " << 4.0f * v1 << "\n";
    std::cout << "v1 / 2.0f = " << v1 / 2.0f << "\n"; 
    std::cout << "v1.dot(v2) = " << v1.dot(v2) << "\n";
}