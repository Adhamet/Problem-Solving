#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int c, n, m;    std::cin >> c >> n >> m;
    std::vector<u64> dp(c + 1);
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;
        dp[x] += 1;
    }

    int mxDay = 0;
    std::vector<int> queries(m);
    std::vector<bool> days(mxDay + 1, false);
    for (int i = 0; i < m; i++) {
        int x;  std::cin >> x;
        queries[i] = x;
        days[x] = true;
        mxDay = std::max(mxDay, x);
    }

    std::vector<u64> ndp(c + 1), ans(mxDay + 1);
    for (int i = 0; i <= mxDay; i++) {
        if (days[i]) {
            ans[i] = std::accumulate(dp.begin(), dp.end(), (u64)0);
        }

        std::fill(ndp.begin(), ndp.end(), 0);
        for (int j = 1; j <= c; j++) {
            if (dp[j] == 0) continue;
            if (j * 2 > c) ndp[j] += dp[j] * 2;
            else ndp[j*2] += dp[j];
        }
        dp.swap(ndp);
    }

    for (int x: queries) std::cout << ans[x] << '\n';
    return 0;
}

