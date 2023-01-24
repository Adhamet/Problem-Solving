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

const int N = 1e4+2, oo = 1e9+7;
int n;
int money[N];   
ll dp[N];

ll solve(int idx)
{
    if(idx >= n)
        return 0;

    if(dp[idx] != -1)
        return dp[idx];
    ll op1=0,op2=0;
    // Leave:
    op1 = solve(idx+1);
    // Take:
    op2 = money[idx] + solve(idx+2);

    return dp[idx] = max(op1,op2);
}

int main()
{
    adhamet
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> money[i];
        memset(dp, -1, sizeof(dp));
        cout << "Case " << i << ": " << solve(0) << el;
    }
    
    return 0;
}