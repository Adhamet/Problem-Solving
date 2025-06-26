#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;	cin >> n >> m;
	int a[n][m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];

	int res = 0;
	for (int i = 0; i < n; ++i) res ^= a[i][0];

	if (res) {
		cout << "TAK" << el;
		for (int i = 0; i < n; ++i) cout << 1 << ' ';
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][0] != a[i][j]) {
				cout << "TAK" << el;
				for (int k = 0; k < n; ++k) {
					if (k != i) cout << 1 << ' ';
					else cout << j + 1 << ' ';
				} 

				return 0;
			}
		}
	}

	return cout << "NIE", 0;
}
