#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'
#define MOD 1000000007

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> vis(n + 1), a(n + 1), b(n + 1), c(n + 1), d(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) c[a[i]] = i;
		for (int i = 1; i <= n; i++) cin >> d[i];

		int ans = 1;
		for (int i = 1; i <= n; i++) if (!vis[i]) {
			bool ok = true;
			vis[i] = true;
			if (d[c[i]] || b[c[i]] == i) ok = false;
			else {
				for (int j = b[c[i]]; j != i; j = b[c[j]]) {
					vis[j] = 1;
					if (d[c[j]]) ok = false;
				}
			}

			if (ok) ans = (ans * 2) % MOD;
		}

		cout << ans << el;
	}

	return 0;
}
