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
		ll n, m, k;
		cin >> n >> m >> k;

		ll sz;
		cin >> sz;

		vector<ll> a(sz);
		for (auto &i: a) cin >> i;

		vector<vector<ll>> grid(n + 5, vector<ll>(m + 5, 0));
		for (int i = 1; i + k - 1 <= n; i++) {
			for (int j = 1; j + k - 1 <= m; j++) {
				grid[i][j] += 1;
				grid[i][j + k] -= 1;
				grid[i + k][j] -= 1;
				grid[i + k][j + k] += 1;
			}
		}

		vector<ll> store;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
				store.push_back(grid[i][j]);
			}
		}

		sort(store.begin(), store.end(), greater<ll>());
		sort(a.begin(), a.end(), greater<ll>());

		ll ans = 0;
		for (int i = 0; i < min(sz, n * m); i++) ans += store[i] * a[i];
		cout << ans << el;
	}

	return 0;
}
