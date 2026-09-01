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
    std::freopen("mosalah.in", "r", stdin);

    int t;
    std::cin >> t;
    while (t--) {
        i64 n, m, x, y;
        std::cin >> n >> m >> x >> y;

        if (y == 0 && m < n * x) {
            std::cout << -1;
            if (t) std::cout << '\n';
            continue;
        }

        i64 ans = std::max(n * (x + y) - m, 0LL);
        std::cout << ans;
        if (t) std::cout << '\n';
    }

    return 0;
}
