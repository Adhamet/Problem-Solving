#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = (int)2e5 + 5;

std::vector<int> g[MXN];
bool dp[MXN][2][3];

void dfs(int u, int p) {
    bool isLeaf = true;
    for (int v: g[u]) {
        if (v == p) continue;
        isLeaf = false;
        dfs(v, u);
    }

    for (int s = 0; s < 2; s++)
        for (int r = 0; r < 3; r++)
            dp[u][s][r] = false;
    dp[u][1][1] = true;     // base case, (also take case)

    if (isLeaf) {
        return;
    }

    bool cur[3] = {true, false, false}; // leave case
    for (int v: g[u]) {
        if (v == p) continue;
        bool child[3] = { // all of what the child can do
            dp[v][0][0] || dp[v][1][0],
            dp[v][0][1] || dp[v][1][1],
            dp[v][0][2] || dp[v][1][2]
        };

        bool nxt[3] = {false, false, false};
        for (int a = 0; a < 3; a++) if (cur[a])
            for (int b = 0; b < 3; b++) if (child[b])
                nxt[(a + b) % 3] = true;

        for (int r = 0; r < 3; r++) cur[r] = nxt[r];
    }

    for (int r = 0; r < 3; r++) dp[u][0][r] = cur[r];
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }

        for (int i = 0, u, v; i < n - 1; i++) {
            std::cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0, 0);

        bool ok = dp[0][0][0] || dp[0][1][0];
        std::cout << (ok? "YES\n": "NO\n");
    }

    return 0;
}
