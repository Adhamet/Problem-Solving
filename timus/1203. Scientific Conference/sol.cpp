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

    int n;  std::cin >> n;
    const int MAX_TE = 3e4 + 4;
    std::vector<int> dp(MAX_TE, 0);

    int lst_te = 0;
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int ts, te;
        std::cin >> ts >> te;
        mp[ts].push_back(te);
        lst_te = std::max(lst_te, te);
    }

    for (int tc = 1; tc <= lst_te + 2; tc++) {
        dp[tc] = std::max(dp[tc], dp[tc - 1]);

        auto it = mp.find(tc);      // it's a start for a period
        if (it != mp.end()) {
            for (auto v: it->second) {
                dp[v + 1] = std::max(dp[v + 1], dp[tc] + 1);
            }
        }
    }

    int ans = 1;
    for (int i = 1; i <= lst_te + 2; i++) {
        // debug(dp[i]);
        ans = std::max(ans, dp[i]);
    }

    return std::cout << ans, 0;
}















// dp [ i ] should carry the best ends so far
// ends: a finished period
// best: carries most passed events
