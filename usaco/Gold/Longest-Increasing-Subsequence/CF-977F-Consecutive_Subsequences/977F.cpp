#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::vector<int> dp(n), par(n, -1);
    std::map<int, int> idx;

    for (int i = 0; i < n; i++) {
        if (idx.find(a[i] - 1) != idx.end()) {
            par[i] = idx[a[i] - 1];
            dp[i] = dp[par[i]] + 1;
        } else par[i] = -1, dp[i] = 1;
        idx[a[i]] = i;
    }

    int mxLen = 0, node = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > mxLen) {
            mxLen = dp[i];
            node = i;
        }
    }

    std::vector<int> ans;
    while (node != -1) {
        ans.push_back(node + 1);
        node = par[node];
    }
    std::reverse(ans.begin(), ans.end());

    std::cout << (int)ans.size() << '\n';
    for (auto x: ans) std::cout << x << ' ';

    return 0;
}
