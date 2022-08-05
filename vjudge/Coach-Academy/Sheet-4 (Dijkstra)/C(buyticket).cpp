//-----
//
// Multi-Source Dijkstra
//
//-----
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair vector<int,int>
const ll N = 2e5+10, oo = 1e18+7;
ll n,m,dist[N],par[N], price[N];
vector<pair<int,ll>> g[N];

void Dijkstra()
{
    // Every node executes at the same time, meaning:
    // Every node will reach the ones closest to them only
    // It won't excute as log(n^2);
    priority_queue<pair<ll,int>> pq;
    for(int i = 1; i<=n; i++)
    {
        dist[i] = price[i];
        pq.push({-dist[i],i});
    }
    while(!pq.empty())
    {
        int node = pq.top().second;
        ll distance = -pq.top().first;
        pq.pop();
        if ( distance > dist[node] )
            continue;
        for( auto child: g[node] )
            if (dist[node] + 2 * child.S < dist[child.F])
            {
                dist[child.F] = dist[node] + 2 * child.S;
                pq.push({-dist[child.F], child.F});
            } 
    }
}

int main()
{
    cin >> n >> m;
    for ( int i = 0 ; i < m ;i++)
    {
        ll u, v ,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for ( int i = 1 ; i <= n ; i++)
        cin >> price[i];
    Dijkstra();
    for(int i = 1; i<=n; i++)
        cout << dist[i] << ' ';
    cout << '\n';
}