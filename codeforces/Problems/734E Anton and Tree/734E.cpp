#include <bits/stdc++.h>
using namespace std;
#define int long long

class Solution {
private:
    vector<vector<int>> adj;
    vector<int> colors;
    int n;
    
    // Get all vertices that would be affected by paint(start)
    vector<bool> getPaintedVertices(int start, vector<int>& currColors) {
        vector<bool> affected(n + 1, false);
        queue<int> q;
        
        q.push(start);
        affected[start] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int next : adj[curr]) {
                if (!affected[next] && currColors[next] == currColors[start]) {
                    affected[next] = true;
                    q.push(next);
                }
            }
        }
        
        return affected;
    }
    
    // Try all possible combinations of paint operations
    int solve_recursive(vector<int> currColors) {
        // Check if all vertices are same color
        bool allWhite = true, allBlack = true;
        for (int i = 1; i <= n; i++) {
            if (currColors[i] == 1) allWhite = false;
            if (currColors[i] == 0) allBlack = false;
        }
        
        if (allWhite || allBlack) return 0;
        
        int minOps = n + 1; // Maximum possible operations needed
        
        // Try paint operation from each vertex
        for (int i = 1; i <= n; i++) {
            vector<bool> affected = getPaintedVertices(i, currColors);
            
            // Try changing to opposite color
            vector<int> newColors = currColors;
            for (int j = 1; j <= n; j++) {
                if (affected[j]) {
                    newColors[j] = 1 - newColors[j];
                }
            }
            
            // Recursively solve for the new configuration
            int ops = solve_recursive(newColors);
            if (ops != -1) {
                minOps = min(minOps, 1 + ops);
            }
        }
        
        return minOps == n + 1 ? -1 : minOps;
    }
    
public:
    int solve(int vertices, vector<int>& inputColors, vector<pair<int,int>>& edges) {
        n = vertices;
        colors = inputColors;
        adj.resize(n + 1);
        
        for (auto& edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        
        return solve_recursive(colors);
    }
};

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> colors(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
    }
    
    vector<pair<int,int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    
    Solution solver;
    cout << solver.solve(n, colors, edges) << '\n';
    
    return 0;
}
