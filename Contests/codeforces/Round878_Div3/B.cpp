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

    int t;  std::cin >> t;
    while (t--) {
        i64 n, k;   std::cin >> n >> k;
        if (k <= 34) {
            i64 x = (1LL << k);
            if (n <= x) std::cout << n + 1 << '\n';
            else std::cout << x << '\n';
        } else std::cout << n + 1 << '\n';
    }

    return 0;
}
