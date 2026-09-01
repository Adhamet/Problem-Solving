#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using dbl = double;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // first friend happy if dish >= x dollars
    // the second is happy if dish >= y% the total bill
    int t;  std::cin >> t;
    while (t--) {
        int x, y;   std::cin >> x >> y;
        if (y == 100) {
            std::cout << -1 << '\n';
            continue;
        }

        bool acc = false;
        int ans = INT_MAX;
        for (int i = x; i <= 10000; i++) {
            for (int j = 1; j <= 10000; j++) {
                if ((i+j)*y <= j*100) {
                    ans = std::min(ans, i+j);
                    acc = true;
                    break;
                }
            }
            if (acc) break;
        }

        std::cout << (ans == INT_MAX? -1: ans) << '\n';
    }

    return 0;
}
