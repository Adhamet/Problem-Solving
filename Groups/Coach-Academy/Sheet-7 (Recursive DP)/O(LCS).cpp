// ~~~~~~~~~~~~~~~~~~~~~~VERY IMPORTANT~~~~~~~~~~~~~~~~~~~~~~ //
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

const int N = 3e3+5, oo = 1e9+7;
int n;
ll dp[N][N];
string str1,str2;

int solve(int i, int j)
{
    if( i == str1.size() || j == str2.size() )
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int op1=0,op2=0;

    // If they match
    if (str1[i] == str2[j])
        op1 = 1 + solve(i+1, j+1);
    // If they dont
    else
        op2 = max(solve(i+1,j), solve(i,j+1));

    return dp[i][j] = max(op1,op2);
}

// IMPORTANT (BUILD) How to build DP?
// This basically traces the best answer to print it out;
void build(int i, int j)
{
    if( i == str1.size() || j == str2.size() )
        return ;

    if(str1[i] == str2[j]) {
        cout << str1[i];
        build(i+1,j+1);
    }
    else {
        if ( solve(i+1,j) > solve(i,j+1) )
            build(i+1, j);
        else 
            build(i, j+1);
    }
    
}

int main()
{
    adhamet
    cin >> str1 >> str2;
    memset(dp, -1, sizeof(dp));
    int x = solve(0,0);
    build(0,0);
}