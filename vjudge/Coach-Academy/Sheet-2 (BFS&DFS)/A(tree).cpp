#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int N = 1e5+10, oo = 1e9;
vector<int> adj[N];
int dist[N],n;

void bfs(int src)
{
    for(int i = 0; i <= n ; i++)
        dist[i] = oo;
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for ( auto child : adj[node] )
            if ( dist[child] > dist[node] )
            {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
    }
}

int main()
{
    fff;
    int m;
    cin >> n >> m;
    if ( n != m + 1 )
        return cout << "NO\n", 0;
    for (int i = 0 ; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    for(int i = 1; i <= n; i++)
    {
        if ( dist[i] == oo )
            return cout << "NO\n", 0;
    }
    cout << "YES\n", 0;
}