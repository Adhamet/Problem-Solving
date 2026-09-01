#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    i64 h;
    std::cin >> n >> h;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    
    std::vector<i64> dWater(n, 0);
    auto findBestDrain = [&]() -> i64 {
        i64 mxWater = 0;
        std::vector<i64> bestWorker(n, 0);

        for (int i = 0; i < n; i++) {
            if (a[i] == h) continue;

            i64 curWater = 0;
            std::vector<i64> curWorker(n, 0);
            
            i64 runningMx = a[i];   
            for (int j = i; j >= 0; --j) {
                runningMx = std::max(runningMx, a[j]);
                curWorker[j] = h - runningMx;;
                curWater += std::max(0LL, curWorker[j] - dWater[j]);
            }

            runningMx = a[i]; 
            for (int j = i + 1; j < n; ++j) {
                runningMx = std::max(runningMx, a[j]);
                curWorker[j] = h - runningMx;;
                curWater += std::max(0LL, curWorker[j] - dWater[j]);
            }

            if (curWater > mxWater) {
                mxWater = curWater;
                bestWorker = curWorker;
            }
        }

        for (int i = 0; i < n; i++)
            dWater[i] = std::max(dWater[i], bestWorker[i]);
        return mxWater;
    };

    std::cout << findBestDrain() + findBestDrain() << '\n';
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
