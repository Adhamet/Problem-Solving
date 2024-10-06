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
		ll n;
		cin >> n;

		vector<ll> a(n);
		for (auto &i: a) cin >> i;
		sort(a.begin(), a.end());

		ll ans = a[0];
		for (int i = 1; i < n; i++) ans = (ans + a[i]) / 2;
		cout << ans << el;
	}

	return 0;
}
