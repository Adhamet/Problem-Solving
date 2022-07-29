#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int N = 1e5+10, oo = 1e9;
vector<int> adj[N];
int dist[8][8];
int dx[] = {2, 2,-2,-2, 1, 1,-1,-1};
int dy[] = {1,-1, 1,-1, 2,-2, 2,-2};
void bfs(int x,int y)
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            dist[i][j] = oo;
    dist[x][y] = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    while (!q.empty())
    {
        pair<int,int> node = q.front();
        q.pop();
        for ( int i = 0; i<8; i++)
        {
            pair<int,int> newNode;
            newNode.first = node.first + dx[i];
            newNode.second = node.second + dy[i];
            if (newNode.first < 0 || newNode.first > 7 || newNode.second < 0 || newNode.second > 7)
                continue;
            if ( dist[node.first][node.second] + 1 < dist[newNode.first][newNode.second] )
            {
                dist[newNode.first][newNode.second] = dist[node.first][node.second] + 1;
                q.push(newNode);
            }
        }
    }
}

int main()
{
    fff;
    string pos1,pos2;
    while (cin>>pos1>>pos2)
    {
        int colFR = pos1[0] - 'a', rowFR = pos1[1] - '1';
        int colTO = pos2[0] - 'a', rowTO = pos2[1] - '1';
        bfs(rowFR, colFR);
        cout << "To get from " << pos1 << " to " << pos2 << " takes " << dist[rowTO][colTO] << " knight moves.";
        cout << endl;
    }
}
