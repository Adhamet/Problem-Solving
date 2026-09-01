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

    int q;  std::cin >> q;
    while (q--) {
        i64 a, b, c;    std::cin >> a >> b >> c;
        i64 x1 = c / 2;
        i64 x2 = (c+1) / 2;
        a += x1, b += x2;
        std::cout << (a + b) / 2 << '\n';
    }

    return 0;
}
