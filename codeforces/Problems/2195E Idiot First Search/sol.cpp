#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

const int MXN = 3e5+3, MOD = (int)1e9+7;

int g[MXN][2];
std::vector<i64> wei;

i64 addm(i64 x, i64 y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

void dfs(int idx) {
    if (idx == 0) return;
    int lft = g[idx][0], rgt = g[idx][1];
    if (lft != 0) dfs(lft), wei[idx] = addm(wei[idx], addm(wei[lft], 1));
    if (rgt != 0) dfs(rgt), wei[idx] = addm(wei[idx], addm(wei[rgt], 1));
    wei[idx] = addm(wei[idx], 1);
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    wei.reserve(MXN);
    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        wei.resize(n + 2);
        std::fill(wei.begin(), wei.end(), 0);

        g[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int x, y;   std::cin >> x >> y;
            g[i][0] = x;
            g[i][1] = y;
        }

        dfs(1);

        std::queue<int> q;
        q.push(0);

        while (!q.empty()) {
            auto node = q.front(); 
            q.pop();
            int lft = g[node][0];
            int rgt = g[node][1];
            if (lft != 0) wei[lft] = addm(wei[lft], wei[node]), q.push(lft);
            if (rgt != 0) wei[rgt] = addm(wei[rgt], wei[node]), q.push(rgt);
        }

        for (int i = 1; i <= n; i++) std::cout << wei[i] << ' ';
        std::cout << '\n';
    }

    return 0;
}
