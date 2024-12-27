#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

const int MAXN = 2e5 + 10;
vector<pair<int, int>> adjL[MAXN];
void dfs(int node, int weight, vector<int> &dist, vector<bool> &vis) {
    vis[node] = true;
    dist[node] = weight;
    for (auto child : adjL[node]) {
        if (!vis[child.first]) {
            dfs(child.first, weight + child.second, dist, vis);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, u, v, w;
        cin >> n;
        for (int i = 1; i <= n; ++i) adjL[i].clear();
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> w;
            adjL[u].push_back({v, w});
            adjL[v].push_back({u, w});
        }

        // firstly get to one of the graph edges
        vector<int> dist1(n + 1, 0), dist2(n + 1, 0);
        vector<bool> vis(n + 1, false);
        dfs(1, 0, dist1, vis);
        int a = max_element(dist1.begin() + 1, dist1.begin() + n + 1) - dist1.begin();

		// calculate distances from both edges
        fill(vis.begin(), vis.end(), false);
        dfs(a, 0, dist1, vis);
        int b = max_element(dist1.begin() + 1, dist1.begin() + n + 1) - dist1.begin();
        fill(vis.begin(), vis.end(), false);
        dfs(b, 0, dist2, vis);

        for (int i = 1; i <= n; i++) cout << max(dist1[i], dist2[i]) << " ";
        cout << el;
    }

    return 0;
}
