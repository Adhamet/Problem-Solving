// Preview
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>
const ll N = 1e5+10, oo = 1e18+7;
ll dist[N][N];
vector< pair<int,intPair> > edges;
int n;
bool negCycle = false;


int main()
{
    fff
    int m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
        for(int j = 1; i <= n; i++)
            if(i != j)
                dist[i][j] = oo;
    for(int i = 0; i < m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for(int i = 1; i <= n; i++)
        if(dist[i][i] < 0)
        {
            cout << "Negative Cycle\n";
            break;
        }
}