#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>
const int N = 1e3+10, oo = 1e9+7;
int dist[N];
vector< pair<int,intPair> > edges;
int n,m;
bool negCycle = false;

int Bellman_Ford(int src)
{
    for(int i = 0; i < n; i++)
        dist[i] = oo;
    dist[src] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[j].S.F, v = edges[j].S.S, w = edges[j].F;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int j = 0; j < edges.size(); j++) {
            int u = edges[j].S.F, v = edges[j].S.S, w = edges[j].F;
            if (dist[u] + w < dist[v]) return 0;
    }
    return 1;
}

int main()
{
    fff
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        edges.clear(); 
        for(int i = 0; i < m; i++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            edges.push_back({w, {u,v}});
        }
        if (Bellman_Ford(0))
            cout << "not ";
        cout << "possible\n";
    }
}