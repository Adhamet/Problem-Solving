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

const int N = 15, oo = 1e9+7;
int n;
int dp[N][N], vis[N][N], seq[N];

int solve(int idx, int last)
{
    // build a base case:
    if ( idx == n+1 )
        return 0;

    if (vis[idx][last])
        return dp[idx][last];
    vis[idx][last] = 1;

    // Have two options whether to take or leave:
    int op1=0,op2=0;

    // First option (leave):    
    op1 = solve(idx+1, last);
    // Second option (take):
    if (seq[idx] > seq[last])
        op2 = 1 + solve(idx+1, idx);
    int ans = max(op1,op2);
    dp[idx][last] = ans;
    return ans;
}

int main()
{
    adhamet
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> seq[i];      
    cout << solve(1,0) << '\n';
}

