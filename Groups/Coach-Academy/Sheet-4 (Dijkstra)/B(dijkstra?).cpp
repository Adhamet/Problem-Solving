// ---
//
// Dijkstra (with path retrival)
//
//---

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair vector<int,int>

const ll N = 2e5+10, oo = 1e16+7;
// including parent:
ll n,m,dist[N],par[N];
vector<pair<int,int>> g[N];

void Dijkstra(int src)
{
    for(int i = 1; i <= n; i++)
        dist[i] = oo;
    dist[src] = 0;

    priority_queue<pair<ll,int>> pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int node = pq.top().S, weight = -pq.top().F;
        pq.pop();
        if(weight > dist[node])
            continue;
        for(auto child : g[node])
            if(dist[node] + child.S < dist[child.F])
            {
                par[child.F] = node;
                dist[child.F] = dist[node] + child.S;
                pq.push({-dist[child.F], child.F});
            }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    Dijkstra(1);
    if(dist[n] == oo)
        return cout << "-1\n", 0;
    vector<int> ans;
    int curr = n;
    while(true)
    {
        ans.push_back(curr);
        if ( curr == 1 ) break;
        curr = par[curr];
    }
    while(!ans.empty())
        cout << ans.back() << " ", ans.pop_back();
    cout << '\n';
}