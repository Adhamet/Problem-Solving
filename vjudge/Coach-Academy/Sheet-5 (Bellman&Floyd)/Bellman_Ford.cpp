// Preview
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>
const ll N = 1e5+10, oo = 1e18+7;
int dist[N];
vector< pair<int,intPair> > edges;
int n;
bool negCycle = false;

void Bellman_Ford(int src)
{
    for(int i = 1; i <= n; i++)
        dist[i] = oo;
    dist[src] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[j].S.F, v = edges[j].S.S, w = edges[j].F;
            if (dist[u] + w < dist[v])
            {
                if(i == n)
                    negCycle = true;
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main()
{
    fff
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back( {w, {u,v}} );
    }
    Bellman_Ford(1);

}