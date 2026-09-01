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
 
    i64 d;
    std::cin >> d;

    i64 T = 2 * d;
    std::vector<std::pair<i64, i64>> ans;
    for (i64 p = 1; p * p <= T; p++) {
        if (T % p != 0) continue;

        i64 q = T / p;

        if ((q - p) % 2 == 0) continue;

        i64 n = (q - p - 1) / 2;
        i64 m = (p + q - 1) / 2;

        if (n > 0) ans.push_back({n, m});
    }

    std::cout << ans.size() << '\n';
    for (auto [x, y]: ans) std::cout << x << ' ' << y << '\n';

    return 0;
}
