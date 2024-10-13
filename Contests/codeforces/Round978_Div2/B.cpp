#include <algorithm>
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
		ll n, x;
		cin >> n >> x;

		ll tot = 0;
		vector<ll> a(n);
		for (int i = 0; i < n; i++) cin >> a[i], tot += a[i];

		ll mx = *max_element(a.begin(), a.end());
		cout << max(mx, ((tot + x - 1) / x)) << el;
	}

	return 0;
}
