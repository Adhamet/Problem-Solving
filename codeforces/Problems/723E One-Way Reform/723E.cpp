#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 205;
int n, m;
vector<int> deg(MAXN);
vector<bool> vis(MAXN);
set<pair<int, int>> blocked;
vector<pair<int, int>> path;
vector<vector<int>> adjmtx(MAXN, vector<int>(MAXN, 0));
void init() {
    fill(deg.begin(), deg.end(), 0);
    fill(vis.begin(), vis.end(), false);
    blocked.clear();
    path.clear();
    adjmtx.assign(MAXN, vector<int>(MAXN, 0));
}

void dfs(int node) {
    vis[node] = true;
    for (int child = 1; child <= n; ++child) {
        while (adjmtx[node][child]) {
            adjmtx[node][child] -= 1;
            adjmtx[child][node] -= 1;
            dfs(child);
            path.push_back({node, child});
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();

        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            adjmtx[u][v] += 1, adjmtx[v][u] += 1;
            deg[u] += 1, deg[v] += 1;
        }

        for (int i = 1; i <= n; ++i) {
            if (deg[i] % 2 == 1) {
                for (int j = i + 1; j <= n; ++j) {
                    if (deg[j] % 2 == 1) {
                        blocked.insert({i, j});
                        adjmtx[i][j] += 1, adjmtx[j][i] += 1;
                        deg[i] += 1, deg[j] += 1;
                        break;
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) if (!vis[i]) {
            dfs(i);
        }

        reverse(path.begin(), path.end());
        for (int i = 1; i <= n; ++i) deg[i] = 0;

        vector<pair<int, int>> ans;
        for (auto ele : path) {
            int a = ele.first, b = ele.second;
            if (blocked.count({a, b}) || blocked.count({b, a})) {
                blocked.erase({min(a, b), max(a, b)});
            } else {
                deg[a] += 1, deg[b] -= 1;
                ans.push_back({a, b});
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 0) cnt += 1;
        }

        cout << cnt << el;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].first << " " << ans[i].second << el;
        }
    }

    return 0;
}
