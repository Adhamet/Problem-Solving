#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 1e4+10;
// Adjancency list:
vector<int> adj[N];
bool vis[N];
void dfs(int node)
{
    vis[node] = true;
    for(auto child : adj[node])
        if(!vis[child])
            dfs(child);
}

// Checking cyclicity;
bool vis2[N];
bool cyclic = false;
void dfs2(int node, int parent)
{
    vis2[node] = true;
    for(auto child : adj[node])
    {
        if(!vis2[child])
            dfs2(child, node);
        else if(child != parent)
            cyclic = true;
    }
}
// --------------------

int main()
{
    fff;
    int n,m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    // First you check if it's connected:
    for(int i=1; i <= n; i++)
        if(!vis[i])
            return cout << "NO\n", 0;
    // Then check if Acyclic or not:
    dfs2(1, 0);
    if (!cyclic)
        cout << "YES\n";
    else cout << "NO\n";
}