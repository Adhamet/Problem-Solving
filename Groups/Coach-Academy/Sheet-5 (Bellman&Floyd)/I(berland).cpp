#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>
const int N = 1e5+10, oo = 1e9+7;
int dist[300+5][300+5];
vector< pair<int,intPair> > edges;
int n;
bool negCycle = false;


int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> dist[i][j];

    int k;
    cin >> k;
    while(k--)
    {
        ll sum=0;
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][a] + dist[a][b] + dist[b][j]);
                dist[i][j] = min(dist[i][j], dist[i][b] + dist[b][a] + dist[a][j]);
                sum += dist[i][j];
            }
        cout << ( sum / 2 ) << '\n';
    }
    return 0;
}