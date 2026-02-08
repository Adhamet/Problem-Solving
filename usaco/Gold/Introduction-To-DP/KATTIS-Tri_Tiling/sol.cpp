#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int N = 32;
    std::vector<std::vector<i64>> dp(N, std::vector<i64>(8));

    dp[0][7] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][0] += dp[i-1][7];

        dp[i][1] += dp[i-1][6];

        dp[i][3] += dp[i-1][4];

        dp[i][4] += dp[i-1][3];
        dp[i][4] += dp[i-1][7];

        dp[i][6] += dp[i-1][1];
        dp[i][6] += dp[i-1][7];

        dp[i][7] += dp[i-1][0];
        dp[i][7] += dp[i-1][4];
        dp[i][7] += dp[i-1][6];
    }

    int n;
    while (std::cin >> n && n != -1) {
        std::cout << dp[n+1][0] << '\n';;
    }

    return 0;
}
