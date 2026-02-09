#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int MXV = 505;

    int n, k;   std::cin >> n >> k;
    int coins[n];
    for (int i = 0; i < n; i++) std::cin >> coins[i];

    std::vector<std::bitset<MXV>> dp(MXV);
    dp[0][0] = 1;
    
    for (int c: coins) {
        for (int s = k; s >= c; s--) {
            dp[s] |= dp[s-c]; 
            dp[s] |= (dp[s-c] << c); 
        }
    }

    std::vector<int> ans;
    for (int i = 0; i <= k; i++) if (dp[k][i])
        ans.push_back(i);

    std::cout << (int)ans.size() << '\n';
    for (auto x: ans) std::cout << x << ' ';
    return 0;
}
