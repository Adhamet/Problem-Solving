#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // each row should be blocked by atleast 1
    // each column should be blocked by atleast 1
    // since we only need YES/NO, we can skip simulation 
    // and just check if the most frequent color leaves 
    // enough space for n blockers

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> cnt(n * n + 3, 0);
        int mxFreq = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a;
                std::cin >> a;
                cnt[a]++;
                mxFreq = std::max(mxFreq, cnt[a]);
            }
        }
        if (mxFreq <= n * n - n) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
