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

const int N = 8e3, oo = 1e9+7;
int input;
int money[5] = {50,25,10,5,1};
int dp[6][N];

int solve(int i, int rem)
{
    if( i >= 4 )
        return 1;
    if (dp[i][rem] != -1)
        return dp[i][rem];
    ll ans = 0;
    if(money[i] <= rem)
        ans += solve(i, rem - money[i]);
    ans += solve(i+1, rem);
    return dp[i][rem] = ans;
}

int main()
{
    adhamet
    while(cin >> input)
    {
        memset(dp, -1, sizeof(dp));
        cout << solve(0, input) << el;
    }
}