#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

void solve()
{
    ll m,n,ans;

    while(cin >> m >> n)
    {
        ans = 0;

        for(int i = 1; i<=m; i++) { ans += (n + (i % 5)) / 5; }
        cout << ans << el;
    }
}
 
int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    solve();
 
	return 0;
}