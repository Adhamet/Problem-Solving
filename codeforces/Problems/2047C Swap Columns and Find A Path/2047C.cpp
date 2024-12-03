#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> mtx(2, vector<int>(n));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mtx[i][j];
			}
		}

		int sum = 0;
		for (int i = 0; i < n; i++) sum += max(mtx[0][i], mtx[1][i]);

		int ans = sum + min(mtx[0][0], mtx[1][0]);
		for (int i = 0; i < n; i++) ans = max(ans, sum + min(mtx[0][i], mtx[1][i]));
		cout << ans << el;
	}

	return 0;
}
