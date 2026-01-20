#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int q;  std::cin >> q;
    while (q--) {
        int n;  std::cin >> n;
        std::vector<int> a(n+1);
        for (int i = 1; i <= n; i++) std::cin >> a[i];

        std::vector<int> cycles, ans(n+1);
        std::vector<bool> vis(n+1, false);
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;

            int p = i;
            while (!vis[p]) {
                vis[p] = true;
                cycles.push_back(p);
                p = a[p];
            }

            int cycleLen = (int)cycles.size();
            for (auto x: cycles) ans[x] = cycleLen;
            cycles.clear();
        }
    
        for (int i = 1; i <= n; i++) std::cout << ans[i] << ' ';
        std::cout << '\n';
    }

    return 0;
}
