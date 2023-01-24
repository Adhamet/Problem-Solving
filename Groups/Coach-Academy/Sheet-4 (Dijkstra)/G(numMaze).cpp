#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ffff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie();
const int N = 1e3+4, oo = 1e9+7;
int n,m,dist[N][N], grid[N][N];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void Dijkstra(int x, int y)
{
    dist[x][y]=grid[x][y];
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({grid[x][y],{x,y}});
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int currX = pq.top().second.first, currY = pq.top().second.second;
        pq.pop();
        if(cost > dist[currX][currY])
            continue;
        for(int i = 0; i < 4; i++)
        {
            int nX = currX + dx[i], nY = currY + dy[i];
            if(nX < 0 || nX >= n || nY < 0 || nY >= m)
                continue;
            if(dist[currX][currY] + grid[nX][nY] < dist[nX][nY])
            {
                dist[nX][nY] = dist[currX][currY] + grid[nX][nY];
                pq.push({-dist[nX][nY], {nX,nY}});
            }
        }
    }
}

int main()
{
    ffff;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int r = 0; r < n; r++)
            for(int c = 0; c < m; c++)
            {
                cin >> grid[r][c];
                dist[r][c] = oo;
            }
        Dijkstra(0,0);
        cout << dist[n-1][m-1] << '\n';
    }
}
