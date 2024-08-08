#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        ll n,l,r;   cin >> n >> l >> r;
        vll a(n), prefix(n+1);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) prefix[i+1]=prefix[i]+a[i];
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ll x = lower_bound(prefix.begin(), prefix.end(), l+prefix[i]) - prefix.begin();
            if(x>n) continue;
            if(prefix[x]-prefix[i] <= r) ans++, i=x-1;
        }
        cout << ans << el;
    }

    return 0;
}
