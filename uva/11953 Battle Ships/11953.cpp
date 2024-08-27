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
const int N = 105, oo = 1e9+2; 
char grid[N][N];
bool vis[N][N];
int n;

bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
void dfs(int x, int y)
{
    if(!valid(x,y) || grid[x][y] == '.' || vis[x][y] == 1)
        return;
    
    vis[x][y] = 1;
    
    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x,y+1);
    dfs(x+1,y);
}
 
int main()
{
    adhamet;
    
    int T,i=1;
    cin >> T;
    while(T--)
    {
        memset(vis, 0, sizeof(vis));
        int ships=0;
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(!vis[i][j] && grid[i][j] == 'x')
                {
                    dfs(i,j);
                    ships++;
                }

        cout << "Case " << i++ << ": " << ships << el;
    }

    return 0;
}