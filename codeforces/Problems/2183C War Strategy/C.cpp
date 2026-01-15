#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, m, i;
        std::cin >> n >> m >> i;

        int l = 1, r = n, ans = 1; // x + y + 1 = t (number of bases)
        while (l <= r) {
            int md = (l + r) >> 1;
            
            int forts1 = i-1;
            int forts2 = n-i;
            if (forts1 > forts2) std::swap(forts1, forts2);

            // div my bases w/ left & right
            int x = std::min(forts1, (md - 1) / 2);
            // y = t - 1 - x;
            int y = md - 1 - x;

            // x + 2y - 1 <= m
            if (x + 2*y - 1 <= m) ans = md, l = md + 1;
            else r = md - 1;
        }

        std::cout << ans << '\n';
    }

    return 0;
}
