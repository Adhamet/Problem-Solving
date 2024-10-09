#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define ll long long
#define el '\n'

// const int N = 1e4 + 5, oo = 1e9;
struct node {
    int ingoing = 0, outgoing = 0;
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, p;
    cin >> n >> p;
    
    node nodes[n + 1];
    vector<vector<int>> weight(n + 1, vector<int>(n + 1));
    for (int i = 0; i < p; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        nodes[u].outgoing = v;
        nodes[v].ingoing = u;
        weight[u][v] = w;
    }
    
    vector<pair<pi, int>> ans;
    auto bfs = [&](int startNode) {
        queue<int> q;
        q.push(startNode);
        
        int minWeight = 1e9;
        int endNode = startNode;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            endNode = node;
            if (nodes[node].ingoing > 0) minWeight = min(minWeight, weight[nodes[node].ingoing][node]);
            if (nodes[node].outgoing != 0) q.push(nodes[node].outgoing);
        }
        
        ans.push_back({{startNode, endNode}, minWeight});
    };
    
    for (int i = 1; i <= n; i++) if (nodes[i].ingoing == 0 && nodes[i].outgoing > 0) {
        bfs(i);
    }
    
    cout << ans.size() << el;
    for (auto a: ans) cout << a.first.first << " " << a.first.second << " " << a.second << el;
    return 0;
}
