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

    int l, h;   std::cin >> l >> h;
    if (h & 1) {
        if (l & 1) std::cout << h;
        else std::cout << (h/2) * 2;
    } else std::cout << h;

    return 0;
}
