#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;
        std::array<i64,2> a, b;
        std::cin >> n >> a[0] >> a[1] >> b[0] >> b[1];

        std::vector<std::array<i64,2>> pts(n);
        for (int i = 0; i < n; i++) std::cin >> pts[i][0];
        for (int i = 0; i < n; i++) std::cin >> pts[i][1];
        std::sort(pts.begin(), pts.end());

        auto dist = [&](std::array<i64,2> v, std::array<i64,2> w) {
            return std::abs(v[0] - w[0]) + std::abs(v[1] - w[1]);
        };

        std::vector<i64> dp(2);
        std::array<i64,2> lowBef = a, highBef = a;
        int i = 0, j = 0;
        while (i < n) {
            std::vector<i64> ndp(2);
            std::array<i64, 2> low = pts[i];
            
            while (i < n && pts[i][0] == low[0])
                i += 1;
            std::array<i64, 2> high = pts[i - 1];

            if (j == 0) {
                ndp[0] = dist(a, high) + dist(high, low);
                ndp[1] = dist(a, low) + dist(low, high);
            } else {
                ndp[0] = dist(high, low) + std::min(dp[0] + dist(lowBef, high),
                                                      dp[1] + dist(highBef, high));
                ndp[1] = dist(low, high) + std::min(dp[0] + dist(lowBef, low),
                                                      dp[1] + dist(highBef, low));
            }

            j += 1;
            lowBef = low;
            highBef = high;
            std::swap(ndp, dp);
        }
        
        std::cout << std::min(dp[0] + dist(lowBef, b), dp[1] + dist(highBef, b)) << '\n';
    }

    return 0;
}
