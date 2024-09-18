#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n); // aj - j = ai - i
		map<int, ll> freq;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			freq[a[i] - i] += 1;
		}

		ll ans = 0;
		for (auto f: freq) ans += (f.S * (f.S - 1)) / 2;
		cout << ans << el;
	}

	return 0;
}
