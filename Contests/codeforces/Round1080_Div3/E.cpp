#include <bits/stdc++.h>

using i64 = long long;

const int MXN = 3e5+3;

int g[MXN][2];
std::vector<int> wei(MXN);

void init_leafs(int idx) {
    bool isLeaf = true;
    for (auto x: g[idx]) {
        isLeaf = false;
        init_leafs(x);
    }
    if (isLeaf) wei[idx] = 1;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::fill(wei.begin(), wei.end(), 0);

        std::vector<int> par(n + 2, 0);
        par[1] = 0;
        for (int i = 1; i <= n; i++) {
            int x, y;   std::cin >> x >> y;
            g[i][0] = x;
            g[i][1] = y;
            if (x != 0) par[x] = i;
            if (y != 0) par[y] = i;
        }

        init_leafs(1);

        std::queue<std::pair<int,i64>> q;
        for (int i = 0; i <= n; i++) {
            if (wei[i] == 1) {
                q.push({i, 1});
            }
        }

        std::vector<int> ans(n + 2, 0);
        while (!q.empty()) {
            auto [node, curVal] = q.front();
            q.pop();

            int lft = g[node][0];
            int rgt = g[node][1];
            if (lft != 0) curVal += wei[lft] + 1;
            if (rgt != 0) curVal += wei[rgt] + 1;
            ans[node] = curVal;
            q.push({par[node], curVal + 1});
        }

        for (int i = 1; i <= n; i++) {
            int lft = g[i][0];
            int rgt = g[i][1];
            int val = ans[i];
            if (lft != 0) val = val - ans[lft] + 1;
            if (rgt != 0) val = val - ans[rgt] + 1;
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
