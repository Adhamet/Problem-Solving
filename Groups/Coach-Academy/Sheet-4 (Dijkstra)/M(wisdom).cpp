//`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'//
//~~~~~~~~UNSOLVED~~~~~~~~~~~~~~~~'//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>
const ll N = 1e5+10, oo = 1e18+7;
int n,m,k;
ll dist[N];  
vector<pair<int, pair<ll,ll>>> adj[N];

void Dijkstra(ll wisdom)
{
    for(int i = 1; i <= n; i++)
        dist[i] = oo;
    dist[1] = 0;
    priority_queue< pair<ll, int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0,1});

    while(!pq.empty()) {
        ll currNode = pq.top().S, cost = pq.top().F;
        pq.pop();

        if(dist[currNode] < cost) continue;
        if(currNode == n) return;
        for(auto child: adj[currNode])
        {
            ll c = child.second.first, wis = child.second.second;
            int next = child.first;

            if(wis <= wisdom && dist[next] > dist[currNode] + c)
            {
                dist[next] = dist[currNode] + c;
                pq.push({dist[next], next});
            } 
        } 
    }
}


int main()
{
    fff
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        for(int i = 0; i <= n; i++)
            adj[i].clear();
        for(int i = 0; i < m; i++)
        {
            int u,v,c,w;
            cin >> u >> v >> c >> w;
            adj[u].push_back({v, {c, w}});
            adj[v].push_back({u, {c, w}});
        }
        int start = 0, end = 1e9, mid, answer = -1;
        while(start <= n)
        {
            mid = (start+end)>>1;
            Dijkstra(mid);
            if(dist[n] < k)
            {
                answer = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        cout << answer << '\n';
    }
}