#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 50+5;
vector<int> adj[N];
bool vis[N];
void dfs(int node)
{
    vis[node]=1;
    for( auto child : adj[node] )
        if(!vis[child])
            dfs(child);
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int headNodes=0;
    for(int i = 1; i <= n; i++)
        if(!vis[i]) {
            dfs(i);
            headNodes++;
        }

    ll int danger=1;
    for(int i = 0; i < n - headNodes; i++)
    {
        danger *= 2;
    }
    cout << danger << endl;
}