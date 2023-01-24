#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int, int>
const ll N = 55, oo = 1e18 + 7;
int dist[N][N];
vector<pair<int, intPair>> edges;
int n;
bool negCycle = false;

void Floyd_Warshall()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    fff int T;
    cin >> T;
    for (int test = 0; test < T; test++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> dist[i][j];
        Floyd_Warshall();
        int orders, totalDist = 0;
        cin >> orders;
        while (orders--)
        {
            ll a, b;
            cin >> a >> b;
            totalDist += dist[a - 1][b - 1];
        }
        cout << "Case #" << test + 1 << ": " << totalDist << '\n';
    }
    return 0;
}