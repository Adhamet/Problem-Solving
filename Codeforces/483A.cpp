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

void solve()
{
    ll n,m,cnt=0;
    cin >> n >> m;
    if(n&1) n++;
    if(abs(n-m) >= 2) cout << n << " " << n+1 << " " << n+2;
    else cout << -1;
}

int main()
{
    adhamet;
    
    solve();
    return 0;
}