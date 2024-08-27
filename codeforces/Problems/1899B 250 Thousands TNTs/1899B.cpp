#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);
 
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<ll> pref(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> pref[i];
			pref[i] += pref[i - 1];
		}

		ll ans = 0;
		for (int i = 1; i <= n; i++) if (n % i == 0) {
			ll mx = LLONG_MIN, mn = LLONG_MAX;
			
			for (int j = i; j <= n; j+=i) {
				mx = max(mx, pref[j] - pref[j - i]);
				mn = min(mn, pref[j] - pref[j - i]);
			}

			ans = max(ans, mx - mn);
		}
		cout << ans << el;
	}

	return 0;
}


