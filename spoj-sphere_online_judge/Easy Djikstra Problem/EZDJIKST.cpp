#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'
const int oo = 1e18;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int V, K;
        cin >> V >> K;
        vector<vector<pair<int, int>>> g(V + 1);
        
        for (int i = 0; i < K; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
        }
        
        int A, B;
        cin >> A >> B;
        
        vector<int> dist(V + 1, oo);
        dist[A] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, A});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (auto [v, w] : g[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        if (dist[B] == oo) cout << "NO" << el;
        else cout << dist[B] << el;
    }

    return 0;
}