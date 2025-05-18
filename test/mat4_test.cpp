#include "test.hpp"

int main() {
    sse::mat4 m(1.0f, 2.0f, 3.0f, 4.0f, 
        2.0f, 3.0f, 4.0f, 5.0f,
        3.0f, 4.0f, 5.0f, 6.0f, 
        4.0f, 5.0f, 6.0f, 7.0f);

    std::cout << m << "\n";

    sse::mat4 m1 = m;
    sse::mat4 m2(2.0f, 3.0f, 4.0f, 5.0f,
        3.0f, 4.0f, 5.0f, 6.0f, 
        4.0f, 5.0f, 6.0f, 7.0f, 
        5.0f, 6.0f, 7.0f, 8.0f);

    std::cout << "m1 + m2 =\n" << m1 + m2 << "\n";
    std::cout << "m1 - m2 =\n" << m1 - m2 << "\n";
    std::cout << "2.0f * m1 =\n" << 2.0f * m1 << "\n";
    std::cout << "m1 / 2.0f =\n" << m1 / 2.0f;

    sse::vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
    std::cout << "m1 * v =\n" << m1 * v << "\n";
} 