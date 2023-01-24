#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie();
const int N = 5e4+10, oo = 1e9+7;
int n,m,dist[N],par[N];
vector<pair<int,int>> g[N];

void Dijkstra(int src)
{
    for(int i = 0; i<n; i++)
        dist[i] = oo;
    dist[src] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int node = pq.top().second;
        int latency = -pq.top().first;
        pq.pop();
        if(latency > dist[node])
            continue;
        for (auto child: g[node])
            if(dist[node] + child.second < dist[child.first])
            {
                dist[child.first] = dist[node] + child.second;
                pq.push({-dist[child.first], child.first});
            }
    }
}

int main()
{
    fff;
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        int S, T;
        cin >> n >> m >> S >> T;
        
        // Init()
        for(int i = 0; i < n; i++)
            g[i].clear();

        int svr1,svr2,l;
        for(int j = 0; j < m; j++)
        {
            cin >> svr1 >> svr2 >> l;
            g[svr1].push_back({svr2,l});
            g[svr2].push_back({svr1,l});
        }
        Dijkstra(S);
        if (dist[T] == oo)
            cout << "Case #" << i << ": " << "unreachable\n";
        else
            cout << "Case #" << i << ": " << dist[T] << '\n';
    }
}