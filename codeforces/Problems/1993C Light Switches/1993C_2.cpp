#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 2e5+10;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;

		vector<ll> a(n);
		for (auto &i : a) cin >> i;

		pll time1 = make_pair(a[0], a[0] + k - 1); // start, end.
		for (int i = 1; i < n; i++) {
			pll time2 = make_pair(a[i], a[i] + k - 1);

			if (time1.first > time2.first) {
				pll tmp = time1;
				time1 = time2;
				time2 = tmp;
			}

			if (time2.first > time1.second) {
				ll increaseBy = (time2.first - time1.second + 2 * k - 1) / (2 * k);
				
				time1.first += increaseBy * 2 * k;
				time1.second += increaseBy * 2 * k;
			}

			time1.first = max(time1.first, time2.first);
			time1.second = min(time1.second, time2.second);

			if (time1.first > time1.second) break;
		}

		if (time1.first > time1.second) {
			cout << -1 << el;
		} else {
			cout << time1.first << el;
		}
	}

	return 0;
}
