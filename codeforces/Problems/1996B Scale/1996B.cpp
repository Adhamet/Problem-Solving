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
		int n, k;
		cin >> n >> k;

		vector<vector<int>> grid(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				char c;
				cin >> c;
				grid[i][j] = c - '0';
			}
		}

		int m = n / k;
		vector<vector<int>> res(m, vector<int>(m));
		for (int i = 0; i < n; i += k) {
			for (int j = 0; j < n; j += k) {
				res[i / k][j / k] = grid[i][j];
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				cout << res[i][j];
			}
			cout << el;
		}
	}

	return 0;
}
