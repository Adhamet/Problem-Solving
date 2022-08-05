#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie();
const int N = 5e4+10, oo = 1e9+7;
int n,m,dist[8][8];
pair<int,int> init, final;
int dx[] = {2, 2,-2,-2, 1, 1,-1,-1};
int dy[] = {1,-1, 1,-1, 2,-2, 2,-2};

void Dijkstra(int x, int y)
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            dist[i][j] = oo;
    dist[x][y] = 0;
    priority_queue <pair <int, pair <int,int>> > pq;
    pq.push({0,{x,y}});
    while(!pq.empty())
    {
        pair<int,int> pos = pq.top().second;
        int moves = -pq.top().first;
        pq.pop();
        for(int i = 0; i < 8; i++)
        {
            pair<int,int> newPos;
            newPos.first = pos.first + dx[i];
            newPos.second = pos.second + dy[i];
            if (newPos.first < 0 || newPos.first > 7 || newPos.second < 0 || newPos.second > 7)
                continue;
            if (dist[pos.F][pos.S] + ( (pos.F*newPos.F) + (pos.S*newPos.S) ) < dist[newPos.F][newPos.S])
            {
                dist[newPos.F][newPos.S] = dist[pos.F][pos.S] + ( (pos.F*newPos.F) + (pos.S*newPos.S) );
                pq.push({-dist[newPos.F][newPos.S],newPos});
            }
        }
    }
}

int main()
{
    while(cin >> init.F >> init.S >> final.F >> final.S)
    {
        Dijkstra(init.F, init.S);
        if (dist[final.F][final.S] == oo)
            cout << -1 << '\n';
        else cout << dist[final.F][final.S] << '\n';
    }
}