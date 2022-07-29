#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define f first
#define s second
const int N = 2e3+10, oo = 1e9;
vector<int> adj[N];
int dist[N][N];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m;
void bfs(int x,int y)
{
    dist[x][y]=0;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty())
    {
        pair<int,int> node = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)  
        {
            pair<int,int> newNode;
            newNode.f = node.f + dx[i], newNode.s = node.s + dy[i];
            if(newNode.f < 1 || newNode.f > n || newNode.s < 1 || newNode.s > m)
                continue;
            if( dist[node.f][node.s] + 1 < dist[newNode.f][newNode.s])
            {   
                dist[newNode.f][newNode.s] = dist[node.f][node.s] + 1;
                q.push(newNode);
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dist[i][j] = oo;
    for(int i = 0; i < k; i++)
    {
        int x,y;
        cin >> x >> y;
        bfs(x,y);
    }
    int x = 1, y = 1, d = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if (dist[i][j] > d)
            {
                d = dist[i][j];
                x = i;
                y = j;
            }
        } 
    cout << x << " " << y << endl;
}