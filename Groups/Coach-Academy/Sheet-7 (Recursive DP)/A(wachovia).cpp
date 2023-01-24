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

const int N = 57, oo = 1e9+7, maxWeight = 1007;
int k,m;
int dp[N][maxWeight], vis[N][maxWeight];
struct bag{
    int weight, value;
}bags[N];

int solve(int idx, int weight)
{
    // build a base case:
    // When is a base case? When you have reached the final bag:
    if (idx == m)
        return 0;

    if (vis[idx][weight])
        return dp[idx][weight];
    vis[idx][weight] = 1;

    // Then we need to have two options ---------------------------------------------------------------
    int op1 = 0, op2 = 0, iW = bags[idx].weight, iV = bags[idx].value;  
    
    // An option to leave the bag (You check the next index, and leave the weight as it is:
    op1 = solve(idx+1, weight);
    // An option to grab the bag (Which occurs if the weight of the truck is obviously bigger):
    if ( weight >= bags[idx].weight)
        op2 = solve(idx+1, weight - iW) + iV; 
    // then we pick the best of the options and return it;
    int ans = max(op1,op2);
    dp[idx][weight] = ans;
    return ans;

}// note: the solve returns the final recursions' best answer and adds it to the previous recursions option whether its op1 or op2 and finds the best answer every-time, though that's only in one cycle, another recursion cycle does the same but the maximum options will help only get the maxium value of all recursive cycles, it saves the best and if one tops it it takes it.


int main()
{
    adhamet
    int T = 1;
    cin >> T;
    while(T--)
    {
        cin >> k >> m;
        for(int i = 0; i < m; i++)
            cin >> bags[i].weight >> bags[i].value;
        memset(vis, 0, sizeof vis);
        cout << "Hey stupid robber, you can get " << solve(0,k) << ".\n";
    }
}