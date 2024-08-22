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

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int n;
ll ans;
vector<ll> a;
bool can(ll k) {
	ll sum = 0, currAns;
	vector<ll> num;
	for (int i = 0; i < n; i++) {
		if ((i + 1) % k) {
			num.push_back(sum);
			sum = 0;
		} else sum += a[i];
	}

	currAns = *max_element(begin(num), end(num)) - *min_element(begin(num), end(num));
	if (currAns > ans) {
		ans = currAns;
		return true;
	} else return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		ans = 0;
		a.clear();
		a.resize(n);
		for (auto &i: a) cin >> i;
	
		ll l = 1, r = n;
		while (l <= r) {
			ll mid = (l + r) / 2;
			dbg(mid);
			if (can(mid)) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		cout << ans << el;
	}

	return 0;
}

