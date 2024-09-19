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

	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);
	for (auto &i: a) cin >> i;
	for (auto &i: b) cin >> i;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin() - 1;
		int d = INT_MAX;

		if (idx >= 0) d = min(d, a[i] - b[idx]);
		if (idx + 1 < m) d = min(d, b[idx + 1] - a[i]);

		ans = max(ans, d);
	}
	
	cout << ans << el;
	return 0;
}
