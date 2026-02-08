#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int MXV = (int)1e6+1;

    int n, x;   std::cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++) std::cin >> coins[i];
    std::sort(coins, coins + n);

    std::vector<int> dp(MXV, INT_MAX);
    for (auto c: coins) dp[c] = 1;

    for (int i = 1; i <= MXV; i++) {
        if (dp[i] == INT_MAX) continue;
        for (auto c: coins) {
            if (i + c > x) continue;
            dp[i + c] = std::min(dp[i + c], dp[i] + 1);
        }
    }

    return std::cout << (dp[x] == INT_MAX? -1: dp[x]), 0;
}
