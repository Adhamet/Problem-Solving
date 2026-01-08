#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define MSB(x) (1LL << (63 - __builtin_clzll(x)))
#define MSB_IDX(x) (63 - __builtin_clzll(x))
#define LSB(x) ((x) & -(x))
#define LSB_IDX(x) (__builtin_ctzll(x))
#define DROP_LSB(x) ((x) & ((x) - 1))
#define IS_POW2(x) ((x) && !((x) & ((x) - 1)))
#define CLZ(x) (__builtin_clzll(x))   // undefined if x == 0
#define CTZ(x) (__builtin_ctzll(x))   // undefined if x == 0

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;  std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;
        if (x == 0) {
            std::cout << 0 << ' ';
            continue;
        }

        int ans = 20;
        for (int k = 0; k <= 15; k++) {
            int xx = x + k;
            int lsb = LSB_IDX(xx);
            ans = std::min(ans, 15 - lsb + k);
        }

        std::cout << ans << ' ';
    }

    return 0;
}
