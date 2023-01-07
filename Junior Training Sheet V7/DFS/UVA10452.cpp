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
const int N = 10, oo = 1e9+2; 
char grid[N][N];
string path = "IEHOVA#", dir[3] = {"forth", "right", "left"};
int n, m, dx[3] = {-1,0,0}, dy[3] = {0,1,-1};
vector<string> result;

bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void dfs(int x, int y, int idx)
{
    if( idx > path.size() ) return;

    for(int k = 0; k < 3; k++)
    {
        int xc = dx[k] + x;
        int yc = dy[k] + y;
        if(valid(xc,yc) && grid[xc][yc] == path[idx])
        {
            result.push_back(dir[k]);
            dfs(xc,yc,idx+1);
        }
    }
}
 
int main()
{
    adhamet;
    
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        int startI,startJ;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == '@') { startI = i; startJ = j; }
            }
        
        result.clear();
        dfs(startI,startJ,0);
        cout << result[0];
        for(int i = 1; i < result.size(); i++) cout << " " << result[i];
        cout << el;
    }

    return 0;
}