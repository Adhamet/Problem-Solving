#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int oo = 1e18+10;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
   
    vector<vector<int>> adj(n + 1), revadj(n + 1);    
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        revadj[v].push_back(u);
    }

    auto bfs = [&](int start, vector<vector<int>> &adj, vector<int> &dist) {
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &child: adj[node]) {
                if (dist[child] > dist[node] + 1) {
                    dist[child] = dist[node] + 1;
                    q.push(child);
                }
            }
        }
    };

    vector<int> distS(n + 1, oo);
    bfs(0, adj, distS);

    vector<int> distA(n + 1, oo);
    bfs(a, revadj, distA);

    vector<int> distB(n + 1, oo);
    bfs(b, revadj, distB);

    int ans = oo;
    for (int i = 0; i <= n; ++i) ans = min(ans, distS[i] + distA[i] + distB[i]);

    cout << ans << el;
    return 0;
}