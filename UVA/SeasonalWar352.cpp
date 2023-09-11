#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'
const int N = 30, oo = 1e9+2; 
char grid[N][N];
bool vis[N][N];
int n;

bool valid(int x, int y)
{
    if(x < 0 || y < 0 || x > n-1 || y > n-1)
        return 0;
    return 1;
}

int cnt = 0;
void dfs(int x, int y)
{
    if( !valid(x,y) || grid[x][y] == '0' || vis[x][y] == 1 )
        return;
    
    vis[x][y] = 1;

    dfs(x-1,y-1);
    dfs(x-1,y);
    dfs(x-1,y+1);
    dfs(x,y-1);
    dfs(x,y+1);
    dfs(x+1,y-1);
    dfs(x+1,y);
    dfs(x+1,y+1);
}
 
int main()
{
    adhamet;
    int img = 1;
    while(cin >> n)
    {
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
                
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i,j);
                    cnt++;
                }
        cout << "Image number " << img++ << " contains " << cnt << " war eagles.\n";
    }

    return 0;
}