#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int dp[1002][1002];

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    int n, m, c;    std::cin >> n >> m >> c;
    int mooney[n + 1];      mooney[0] = 0;
    for (int i = 0; i < n; i++) std::cin >> mooney[i];

    std::vector<int> g[n];
    for (int i = 0; i < m; i++) {
        int u, v;   std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    
    for (int t = 0; t <= 1000; t++) 
        for (int i = 0; i < n; i++)
            dp[t][i] = -1;
    dp[0][0] = 0;
    
    int ans = 0;
    for (int t = 0; t <= 1000; t++) {
        for (int i = 0; i < n; i++) {
            if (dp[t][i] == -1) continue;

            for (auto v: g[i]) {
                if (t + 1 >= 1000) break;
                dp[t + 1][v] = std::max(dp[t + 1][v], dp[t][i] + mooney[v]);
            }
        }

        ans = std::max(ans, dp[t][0] - c * t * t);
    }

    return std::cout << ans, 0;
}
