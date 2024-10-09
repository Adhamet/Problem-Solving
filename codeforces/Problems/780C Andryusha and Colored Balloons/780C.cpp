#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define ll long long
#define el '\n'

// const int N = 1e4 + 5, oo = 1e9;
struct node {
    int val, color, parColor;
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    
    int ans[n + 1];
    bool vis[n + 1] = {false};
    vector<int> adjL[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    
    int mx = 0;
    auto bfs = [&](int start) {
        queue<node> q;
        q.push({start, 1, -1});
        vis[start] = true;
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            mx = max(mx, curr.color);
            ans[curr.val] = curr.color;
            
            int i = 1;
            for (auto child: adjL[curr.val]) {
                if (!vis[child]) {
                    while (i == curr.color || i == curr.parColor) i += 1;
                    vis[child] = true;
                    q.push({child, i, curr.color});
                    i += 1;
                }
            }
        }
    };
    
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        bfs(i);
    }
    
    cout << mx << el;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
