#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<i64> coins(n);
    for (int i = 0; i < n; i++) std::cin >> coins[i];

    std::vector<bool> dp((int)1e5+2, 0);
    dp[0] = 1;

    for (int c: coins) {
        for (int i = 100000; i >= c; i--) {
            dp[i] = dp[i] | dp[i - c];
        }
    }

    std::set<int> st;
    for (int i = 1; i <= 100000; i++) {
        if (dp[i]) st.insert(i);
    }

    std::cout << (int)st.size() << '\n';
    for (auto x: st) std::cout << x << ' ';
    return 0;
}
