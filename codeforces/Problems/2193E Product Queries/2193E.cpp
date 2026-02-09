#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int MXV = (int)3e5+5;

    std::vector<std::vector<int>> divs(MXV);
    for (int i = 1; i < MXV; i++) {
        for (int j = 1; (i64)j*j <= (i64)i; j++) {
            if (i % j == 0) {
                divs[i].push_back(j);
                if (i/j != j) divs[i].push_back(i/j);
            }
        }
        std::sort(divs[i].begin(), divs[i].end());
    }

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        int a[n];
        std::vector<int> dp(n + 1, (int)1e8);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            dp[a[i]] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int d: divs[i]) {
                dp[i] = std::min(dp[i], dp[d] + dp[i/d]);
            }
            std::cout << (dp[i] == (int)1e8? -1: dp[i]) << ' ';
        }

        std::cout << '\n';
    }

    return 0;
}
