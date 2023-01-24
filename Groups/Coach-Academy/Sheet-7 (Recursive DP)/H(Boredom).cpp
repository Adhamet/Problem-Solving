#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

const int N = 1e5+5, oo = 1e9+7;
int n;
ll freq[N];
ll dp[N];

ll solve(int idx)
{
    if(idx > 1e5)
        return 0;
    if(dp[idx] != -1)
        return dp[idx];

    //take or leave
    ll take = freq[idx] * idx + solve(idx+2);
    ll leave = solve(idx+1);
    return dp[idx] = max(take,leave);
}

int main()
{
    adhamet
    cin >> n;
    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }
    memset(dp,-1,sizeof(dp));
    cout << solve(0) << el;
    return 0;
}