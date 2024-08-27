#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'
 
int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    ll n,m,ans;
    cin >> n >> m;
    ans = 0;
    for(int i = 1; i<=n; i++) { ans += (m + (i % 5)) / 5; }
    cout << ans << el;
 
	return 0;
}
