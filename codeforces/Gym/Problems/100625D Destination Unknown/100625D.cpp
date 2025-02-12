#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m, t; cin >> n >> m >> t;
        int s, g, h; cin >> s >> g >> h;
        s--; g--; h--;
        
        vector<vector<array<int, 2>>> graph(n);
        int ghW = 0;
        for (int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            u--; v--;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
            if ((u == g && v == h) || (u == h && v == g)) ghW = w;
        }
        
        auto dijkstra = [&](int start) {
            const int oo = 1e18 + 10;
            vector<int> dist(n, oo);
            priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
            pq.push({0, start});
            dist[start] = 0;
            
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                
                if (d > dist[u]) continue;
                
                for (auto [v, w] : graph[u]) {
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        };
        
        vector<int> destinations(t);
        for (auto& x: destinations) { cin >> x; x--; }
        
        auto distS = dijkstra(s);
        auto distG = dijkstra(g);
        auto distH = dijkstra(h);
        
        vector<int> ans;
        for (int x: destinations) {
            bool validPath = false;
            if (distS[g] + ghW + distH[x] == distS[x]) validPath = true;
            if (distS[h] + ghW + distG[x] == distS[x]) validPath = true;
            if (validPath) ans.push_back(x + 1);
        }
        
        sort(ans.begin(), ans.end());
        for (int x : ans) cout << x << ' ';
        cout << el;
    }

    return 0;
}