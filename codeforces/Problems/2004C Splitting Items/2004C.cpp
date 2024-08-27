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
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (auto &i: a) cin >> i;
		sort(begin(a), end(a), greater<int>());

		vector<int> alice, bob;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) alice.push_back(a[i]);
			else bob.push_back(a[i]);
		}

		ll sum = 0;
		for (int i = 0; i < min(alice.size(), bob.size()); i++) {
			if (k > 0) {
				int diff = abs(bob[i] - alice[i]);
				bob[i] += min(k, diff);
				k -= min(k, diff);
			}
			
			sum += alice[i] - bob[i];
		}
		cout << (bob.size() < alice.size() ? sum + alice.back(): sum) << el;
	}

	return 0;
}
