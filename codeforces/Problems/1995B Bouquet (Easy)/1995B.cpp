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
		ll n, m;
		cin >> n >> m;
		
		vector<ll> vec(n);
		for (auto &i: vec) cin >> i;
		
		sort(begin(vec), end(vec));
		
		ll maxCost = 0, currCost = 0;

		int l = 0, r = 0;
		while (r < n) {
			currCost += vec[r];
			
			while (vec[r] - vec[l] > 1) currCost -= vec[l++];
			while (l <= r && currCost > m) currCost -= vec[l++];

			maxCost = max(maxCost, currCost);
			r += 1;
		}

		cout << maxCost << el;
	}

	return 0;
}
