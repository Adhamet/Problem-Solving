#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		ll k;
		cin >> k;

		ll l = 1, r = LLONG_MAX - 1, ans = 0;
		while (l <= r) {
			ll mid = (l + r) / 2;

			ll val = sqrtl(mid);
			if (mid - val >= k) r = mid - 1, ans = mid;
			else l = mid + 1;
		}

		cout << ans << el;
	}

	return 0;
}
