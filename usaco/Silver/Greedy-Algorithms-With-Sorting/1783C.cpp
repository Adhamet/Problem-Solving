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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		for (auto &i: a) cin >> i;
		auto b = a;
		sort(b.begin(), b.end());

		int wins = 0;
		for (int i = 0; i < n && m >= b[i]; i++) m -= b[i], wins += 1;
		if (wins != 0 && wins != n && m + b[wins - 1] >= a[wins]) wins += 1;
		cout << n + 1 - wins << el;
	}
	
	return 0;
}
