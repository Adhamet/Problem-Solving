#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    i64 x;  std::cin >> x;

    std::vector<i64> price(n), pages(n);
    for (int i = 0; i < n; i++) std::cin >> price[i];
    for (int i = 0; i < n; i++) std::cin >> pages[i];
    
    std::vector<i64> dp(x + 2, -1);
    dp[x] = 0;
    
    for (int i = 0; i < n; i++) {
        std::vector<i64> ndp = dp;
        for (int j = price[i]; j <= x; j++) {
            if (ndp[j] == -1) continue;
            int v = j - price[i];
            ndp[v] = std::max(ndp[v], ndp[j] + pages[i]);
        }
        std::swap(dp, ndp);
    }

    i64 ans = 0;
    for (int i = 0; i <= x; i++) ans = std::max(ans, dp[i]);

    return std::cout << ans, 0;
}
