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

const int N = 1007, oo = 1e9+7;
int n;
int dp[N][N], vis[N][N];
string str1,str2;


int solve(int i, int j)
{
    // build a base case:
    if ( i == str1.size() || j == str2.size() )
        return 0;

    if (vis[i][j])
        return dp[i][j];
    vis[i][j] = 1;

    // Have two options whether the first matched or not:

    // First option (They matched)
    int op1=0,op2=0;
    if (str1[i] == str2[j])
        op1 = 1 + solve(i+1, j+1);
    // Second option (They didn't match)
    // which itself has two options, whether to increase the 1st string or increase 2nd string
    else{
        op2 = max( solve(i+1,j), solve(i,j+1) );
    }
    int ans = max(op1,op2);
    return dp[i][j] = ans;
}

int main()
{
    adhamet
    while(getline(cin, str1) && getline(cin, str2))
    {
        memset(vis,0,sizeof(vis));
        cout << solve(0,0) << el;
    }
}

