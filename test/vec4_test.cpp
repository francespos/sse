#include "test.h"
#include <cassert>

int main() {
    sse::vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
    sse::vec4 v1 = v;
    sse::vec4 v2(2.0f, 3.0f, 4.0f, 5.0f);

    assert(v == v1);
    assert(v1 != v2);

    assert(v1 + v2 == sse::vec4(3.0f, 5.0f, 7.0f, 9.0f));
    assert(v1 - v2 == sse::vec4(-1.0f, -1.0f, -1.0f, -1.0f));
    assert(v1 * 2.0f == sse::vec4(2.0f, 4.0f, 6.0f, 8.0f));
    assert(v1 / 2.0f == sse::vec4(0.5f, 1.0f, 1.5f, 2.0f));

    assert(v1.dot(v2) == 40);
    assert(2.0f * v1 == sse::vec4(2.0f, 4.0f, 6.0f, 8.0f));

    v1 = v;
    v1 += v2;
    assert(v1 == sse::vec4(3.0f, 5.0f, 7.0f, 9.0f));

    v1 = v;
    v1 -= v2;
    assert(v1 == sse::vec4(-1.0f, -1.0f, -1.0f, -1.0f));

    v1 = v;
    v1 *= 2.0f;
    assert(v1 == sse::vec4(2.0f, 4.0f, 6.0f, 8.0f));

    v1 = v;
    v1 /= 2.0f;
    assert(v1== sse::vec4(0.5f, 1.0f, 1.5f, 2.0f));
}