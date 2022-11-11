#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define ull unsigned ll /* longer than Long Long */
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

const int N = 57, oo = 1e9+7, maxWeight = 1007;
int k,m;
int dp[N][maxWeight], vis[N][maxWeight];
struct bag{
    int weight, value;
}bags[N];

int main()
{
    adhamet
    int T;
    cin >> T;
    while(T--)
    {
        cin >> k >> m;

        for(int i = 1; i <= m; i++)
            cin >> bags[i].weight >> bags[i].value;
        
        for(int idx = 1; idx <= m; idx++)
        {
            for(int W = 0; W <= k; W++) 
            {
                int w = bags[idx].weight, val = bags[idx].value;

                // Leave:
                dp[idx][W] = dp[idx-1][W];
                // Take:
                if ( W >= w )
                    dp[idx][W] = max(dp[idx][W], dp[idx-1][W-w] + val);
            }
        }
        cout << "Hey stupid robber, you can get " << dp[m][k] << ".\n";
    }
}