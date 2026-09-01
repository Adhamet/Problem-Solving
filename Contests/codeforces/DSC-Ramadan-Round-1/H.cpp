#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // z^2 - xy = 1
    // z^2 = 1 + xy
    // xy = z^2 - 1
    // y = (z^2 - 1) / y
    // since x is integer and y is integer therefore
    // (z^2 - 1) == 0 (mod y)
    // the first perfect square s.t. its -1 is divides y and divides x
    //

    return 0;
}
