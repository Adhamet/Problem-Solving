#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define u64 uint64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int n, m;	cin >> n >> m;
		vector<vector<u64>> grid(n, vector<u64>(m));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				grid[i][j] = (i * 256 + j) % (1ULL << 63);

		cout << n * m << el;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << grid[i][j] << ' ';
			} cout << el;
		}
	}  return 0;
}
