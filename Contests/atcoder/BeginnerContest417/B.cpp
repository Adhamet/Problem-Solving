#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<int> a(n);	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<bool> vis(n, false);
	for (int i = 0; i < m; ++i) {
		int x;	cin >> x;
		for (int i = 0; i < n; ++i) if (a[i] == x && !vis[i]) {
			vis[i] = true;
			break;
		}
	}

	for (int i = 0; i < n; ++i) if (!vis[i]) cout << a[i] << ' ';
	return 0;
}
