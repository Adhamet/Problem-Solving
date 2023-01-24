// Couldn't solve it
// The input/output is so annoying!!!

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define f first
#define s second
const int N = 25, oo = 1e9;
vector<int> results;
bool grid[N][N];
bool vis[N][N];
int dist[N][N]; 
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
void bfs(int x, int y)
{
    int cnt=1;
    vis[x][y]=1;
    dist[x][y]=0;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty())
    {
        pair<int,int> node = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            pair<int,int> newNode;
            newNode.f = node.f + dx[i], newNode.s = node.s + dy[i];
            if (newNode.f < 0 || newNode.f > 24 || newNode.s < 0 || newNode.s > 24)
                continue;
            if (grid[newNode.f][newNode.s] == 1 && !vis[newNode.f][newNode.s])
                if(dist[newNode.f][newNode.s] > dist[node.f][node.s] + 1)
                {
                    cnt++;
                    vis[newNode.f][newNode.s] = true;
                    dist[newNode.f][newNode.s] = dist[node.f][node.s] + 1;
                    q.push(newNode);
                }
        }
    }
    results.push_back(cnt);
}

int main()
{
    fff;
    int t;
    cin >> t;
    while(t--)
    {
        results.clear();
        for(int i = 0; i < 25; i++)
            for(int j = 0; j < 25; j++)
            {
                dist[i][j] = oo;
                vis[i][j] = 0;
            }
        string s;
        cin >> s;

        int row = 0;

        while(s != "")  
        {
            for(int c = 0; c < s.length(); c++)
                if(s[c] == '1')
                    grid[row][c] = 1;
            cin >> s;
            row++;
        }
        for(int i = 0; i < 25; i++)
            for(int j = 0; j < 25; j++)
                if(!vis[i][j] && grid[i][j] == 1)
                    bfs(i,j);
        int sol = 0;
        for (auto result : results)
            sol = max(sol, result);
        cout << sol << endl;
    }
}