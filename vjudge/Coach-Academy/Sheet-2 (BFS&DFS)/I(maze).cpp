#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define f first
#define s second
#define intPair pair<int,int>
const int N = 5e2+5, oo = 1e9;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
char grid[N][N];
bool vis[N][N];
vector<intPair> v;
void dfs(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        intPair node = {x+dx[i],y+dy[i]};
        if(node.f<=0 && node.f > n && node.s<=0 && node.s > m)
            continue;
        if(grid[node.f][node.s]=='.' && !vis[node.f][node.s])
        {
            vis[node.f][node.s] = 1;
            dfs(node.f,node.s);
        }
    }
    v.push_back({x,y});
}

int main()
{
    int k;
    cin >> n >> m >> k;
    intPair first;
    first.f = -1;
    first.s = -1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if(first.f==-1 && grid[i][j] == '.')
                first.f = i, first.s = j;
        }
    dfs(first.f,first.s);
    for(int i = 0; i < k; i++)
    {
        intPair X = v[i];
        grid[X.f][X.s] = 'X';
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            j<m? cout << grid[i][j]: cout << grid[i][j] << endl;
}
