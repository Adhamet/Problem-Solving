#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair vector<int,int>
const ll N = 2e5+10, oo = 1e18+7;
ll n,m,dist[N];
vector<pair<int, pair<ll,ll>>> g[N];

void Dijkstra()
{
    for(int i = 0; i < n; i++)
        dist[i] = oo;
    dist[1] = 0;
    priority_queue< pair</**/ pair<ll,ll>, pair< ll,int> /**/> > pq;

}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> n >> m >> k;
        for(int i=0; i < n; i++)
        {
            g[N].clear();
        }

        for(int i=0; i < m; i++)
        {
            int u,v,w,c;
            wisdom[u].push_back({v,w});
            wisdom[v].push_back({u,w});
            cost[u].push_back({v,c});
            cost[v].push_back({u,c});
        }
        Dijkstra();

        if(dist[n-1] == oo)
            cout << -1 << '\n';
        else cout << dist[n-1] << '\n';
    }
}