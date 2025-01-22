#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int color, vector<vector<int>>& adj, vector<int>& colors) {
    colors[v] = color;
    for(int u : adj[v]) {
        if(colors[u] == -1) {
            dfs(u, color, adj, colors);
        }
    }
}

vector<int> find_components(vector<pair<int,int>>& edges, int n) {
    // Create adjacency list
    vector<vector<int>> adj(n);
    for(auto [u, v] : edges) {
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    
    // DFS to color components
    int color = 0;
    vector<int> colors(n, -1);
    
    // Find all components
    for(int v = 0; v < n; v++) {
        if(colors[v] == -1) {
            dfs(v, color, adj, colors);
            color++;
        }
    }
    
    return colors;
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    
    // Read edges for graph F
    vector<pair<int,int>> edges_f(m1);
    for(int i = 0; i < m1; i++) {
        cin >> edges_f[i].first >> edges_f[i].second;
    }
    
    // Read edges for graph G
    vector<pair<int,int>> edges_g(m2);
    for(int i = 0; i < m2; i++) {
        cin >> edges_g[i].first >> edges_g[i].second;
    }
    
    // Find components in both graphs
    vector<int> comp_f = find_components(edges_f, n);
    vector<int> comp_g = find_components(edges_g, n);
    
    // For each pair of vertices, check if they are connected in F but not in G
    // or connected in G but not in F
    int operations = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            bool connected_f = (comp_f[i] == comp_f[j]);
            bool connected_g = (comp_g[i] == comp_g[j]);
            if(connected_f != connected_g) {
                operations++;
            }
        }
    }
    
    cout << operations/2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
