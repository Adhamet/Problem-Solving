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

void solve(int n,int m, int c)
{
    if ( c == 0 ) { cout << (n-7)*(m-7)/2 << el; }
    else { cout << ( (n-7)*(m-7)+1 )/2 << el; }
}

int main()
{
    adhamet

    int n,m,c;
    while(cin >> n >> m >> c && n+m+c != 0)
        solve(n,m,c);
    return 0;
}