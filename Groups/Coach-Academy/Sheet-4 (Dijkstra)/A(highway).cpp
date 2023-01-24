// ---
//
// Dijkstra (normal)
// Method to get lowest cost path. O(n)
//
//---

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair vector<int,int>

const int N = 1e5+10, oo = 1e9;
int n,m,dist[N];
vector<pair<int,int>> g[N];

void Dijkstra(int src)
{
    for(int i = 1; i <= n; i++)
        dist[i] = oo;
    dist[src] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int currNode = pq.top().S, distance = -pq.top().F;
        pq.pop();
        if ( distance > dist[currNode] )
            continue;
        for ( auto child : g[currNode] )
            if(dist[currNode] + child.S < dist[child.F])
            {
                dist[child.F] = dist[currNode] + child.S;
                pq.push({-dist[child.F],child.F});
            }
    }
}

int main()
{
    fff;
    int t;
    cin >> t;
    while(t--)
    {
        int src, final;
        cin >> n >> m >> src >> final;
        for(int i = 0; i < m; i++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        Dijkstra(src);
        if(dist[final] == oo)
            cout << "NONE\n";
        else
            cout << dist[final] << '\n';
    }
}