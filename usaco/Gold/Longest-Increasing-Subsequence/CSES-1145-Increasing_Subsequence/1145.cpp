#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        int j = std::upper_bound(a,)
    }

    std::vector<int> output;
    int lst = std::max_element(dp.begin(), dp.end()) - dp.begin();
    output.push_back(a[lst]);

    for (int i = lst - 1; i >= 0; i--) {
        if (a[i] < a[lst] && dp[i] == dp[lst] - 1) {
            lst = i;
            output.push_back(a[lst]);
            if (dp[lst] == 1) break;
        }
    }
    std::reverse(output.begin(), output.end());

    std::cout << (int)output.size() << '\n';
    for (auto o: output) std::cout << o << ' ';
    return  0;
}
