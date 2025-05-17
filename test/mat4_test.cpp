#include <sse/mat4.hpp>
#include <iostream>

std::ostream& operator<<(std::ostream& out, sse::mat4& m) {
    for (size_t i = 0; i < 4; ++i) {
        out << "[ ";

        for (size_t j = 0; j < 4; ++j) {
            out << m[i][j] << " ";
        }

        out << "]\n";
    }

    return out;
}

int main() {
    sse::mat4 m(1.0f, 2.0f, 3.0f, 4.0f, 
        2.0f, 3.0f, 4.0f, 5.0f,
        3.0f, 4.0f, 5.0f, 6.0f, 
        4.0f, 5.0f, 6.0f, 7.0f);

    std::cout << m << "\n";
} 