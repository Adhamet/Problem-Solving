#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

ll n,k;
bool can(ll num) {
	
}

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t;	cin >> t;
    while(t--) {
		cin >> n >> k;
		if (n == k) return cout << 1, 0;
		ll l=0, r=n, mid, ans=0;
		while(l <= r) {
			mid = (l+r)/2;

			if (can(mid)) { ans = mid; r = mid - 1; }
			else l = mid - 1;
		}

	}

    return 0;
}