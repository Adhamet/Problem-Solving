#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int INF = INT_MAX;

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) std::cin >> a[i];


        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int turn = 0; turn < 2; turn++) {
                if (dp[i][turn] == INF) continue;

                for (int k = 1; k <= 2 && i + k <= n; k++) {
                    int cost = 0;

                    if (turn == 0) {
                        for (int j = 0; j < k; j++) {
                            cost += a[i + j];
                        }
                    }

                    dp[i + k][turn ^ 1] = std::min(dp[i+k][turn^1],
                                                    dp[i][turn]+cost);
                }
            }
        }

        std::cout << std::min(dp[n][0], dp[n][1]) << '\n';
    }

    return 0;
}

