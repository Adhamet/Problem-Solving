#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

int n,k;
int a[1002], b[1002];
bool can(int cookies)
{
    int cost = 0;
    for(int i = 0; i < n; i++) {
        cost += max((cookies * a[i]) - b[i], 0);
        if ( cost > k )
            return false;
    }
    return true;
}

void solve() 
{
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int l = 0, r = 2000, ans;
    while( l <= r ) {
        int mid = l + (r - l)/2;

        if (can(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << el;
}

int main() 
{/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
    int t = 1;
    while(t--)
        solve();

	return 0;
}
