#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, ones = 0;	cin >> n;
		vector<vector<char>> mtx(n, vector<char>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> mtx[i][j];
				ones += (mtx[i][j] == '1');
			}
		}

		if (n == 1) {
			if (mtx[0][0] == '1') cout << "0\n";
			else cout << "1\n";
			continue;
		}

		vector<int> diag(n, 0);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (mtx[i][j] == '1')
					diag[(i - j + n) % n]++;

		int cnt = *max_element(diag.begin(), diag.end());
		cout << ones - cnt + (n - cnt) << '\n'; 
	}

	return 0;
}
