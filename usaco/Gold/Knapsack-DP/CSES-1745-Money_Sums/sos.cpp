#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int MXV = 100000;

    int n;  std::cin >> n;
    std::vector<i64> coins(n);
    for (int i = 0; i < n; i++) std::cin >> coins[i];

    std::bitset<MXV+1> dp;
    dp[0] = 1;
    for (int c: coins) dp |= (dp << c);

    std::set<int> st;
    for (int i = 1; i <= MXV; i++) {
        if (dp[i]) st.insert(i);
    }

    std::cout << (int)st.size() << '\n';
    for (auto x: st) std::cout << x << ' ';
    return 0;
}

