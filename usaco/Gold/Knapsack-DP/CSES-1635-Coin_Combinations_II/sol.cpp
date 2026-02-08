#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int MXV = (int)1e6+1, MOD = (int)1e9+7;

    int n, x;   std::cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++) std::cin >> coins[i];
    std::sort(coins, coins + n);

    std::vector<i64> dp(MXV, 0);    dp[0] = 1;
    for (auto c: coins) {
        for (int i = c; i <= x; i++) {
            dp[i] += dp[i - c];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }

    return std::cout << dp[x], 0;
}
