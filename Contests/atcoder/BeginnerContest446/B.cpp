#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, m;   std::cin >> n >> m;
    std::vector<int> ans(n, 0);
    std::vector<bool> vis(m, false);

    std::vector<std::vector<int>> a;
    for (int i = 0; i < n; i++) {
        int l;  std::cin >> l;
        a.push_back(std::vector<int>(l));
        for (int j = 0; j < l; j++) {
            std::cin >> a.back()[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto x: a[i]) {
            if (!vis[x]) {
                ans[i] = x;
                vis[x] = true;
                break;
            }
        }
    }

    for (auto x: ans) std::cout << x << '\n';

    return 0;
}
