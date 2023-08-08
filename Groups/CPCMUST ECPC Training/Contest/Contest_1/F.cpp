#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
 
void solve()
{
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    ll sum = 0;
    char g[n+1][m+1];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '.')
            {
                if (j < m - 1 && g[i][j+1] == '.' && y < x*2)
                {
                     sum += y;
                     j++;
                }
                else
                    sum += x;
            }
        }
    
    cout << sum << '\n';
}
 
int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    int t;
    cin >> t;
    while(t--){
    solve();
    }
 
	return 0;
}
