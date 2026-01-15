#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define MSB_IDX(x) (63 - __builtin_clzll(x))

constexpr int MOD = 998244353;

void solve() {
    i64 n, m;   std::cin >> n >> m;
    if (n == 1) std::cout << m + 1 << '\n';
    else {
        i64 msb = MSB_IDX(m);
        std::cout << 2LL * (((i64)m - (1 << msb) + 1) % MOD) % MOD << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

