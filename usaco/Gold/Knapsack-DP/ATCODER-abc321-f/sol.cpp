#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int MOD = (int)998244353;

    int q, k;   std::cin >> q >> k;
    std::vector<int> dp(k + 2, 0);
    dp[0] = 1;

    while (q--) {
        char type;
        int x;
        std::cin >> type >> x;

        if (type == '+') {
            for (int i = k; i >= x; i--) {
                dp[i] += dp[i - x];
                if (dp[i] >= MOD) dp[i] -= MOD;
            }
        } else {
            for (int i = x; i <= k; i++) {
                dp[i] -= dp[i - x];
                if (dp[i] < 0) dp[i] += MOD;
            }
        }

        std::cout << dp[k] << '\n';
    }

    return 0;
}
