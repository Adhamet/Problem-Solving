#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int m; std::cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; ++j) std::cin >> a[i][j];
    }

    for (int i = 0; i < n; i++) {
        std::reverse(a[i].begin(), a[i].end());

        std::vector<int> tmp;
        std::unordered_set<int> vis;
        tmp.reserve(a[i].size());
        for (int x : a[i]) {
            if (!vis.count(x)) {
                vis.insert(x);
                tmp.push_back(x);
            }
        }
        a[i].swap(tmp);
    }

    std::vector<char> vis((int)1e6+3, 0);
    std::vector<int> ans;
    std::vector<bool> used(n, false);
    auto compare = [&](int idx1, int idx2) {
        int p1 = 0, p2 = 0;
        int sz1 = a[idx1].size(), sz2 = a[idx2].size();

        while (true) {
            while (p1 < sz1 && vis[a[idx1][p1]]) p1++;
            while (p2 < sz2 && vis[a[idx2][p2]]) p2++;

            if (p1 == sz1 && p2 == sz2) return false; 
            if (p1 == sz1) return true;
            if (p2 == sz2) return false;

            if (a[idx1][p1] != a[idx2][p2]) {
                return a[idx1][p1] < a[idx2][p2];
            }

            p1++; p2++;
        }
    };

    for (int step = 0; step < n; ++step) {
        int bestIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            if (bestIdx == -1 || compare(i, bestIdx)) {
                bestIdx = i;
            }
        }

        used[bestIdx] = true;
        for (int x: a[bestIdx]) {
            if (!vis[x]) {
                vis[x] = 1;
                ans.push_back(x);
            }
        }
    }

    for (int i = 0; i < (int)ans.size(); ++i)
        std::cout << ans[i] << ' ';
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
