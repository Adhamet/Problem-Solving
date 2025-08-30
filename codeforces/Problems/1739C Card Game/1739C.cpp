#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int MXN = 62, MOD = 998244353;

	i64 c[MXN][MXN];	// pascal triangle | binomial coefficient
	for (int i = 0; i < MXN; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j] + MOD) % MOD;
		}
	}

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		i64 win = 0;
		for (int i = 0; i < n; ++i) {
			if (i % 4 == 0 || i % 4 == 3) {
				int a = n - i - 1;
				int b = (n / 2) - (i / 4 * 2 + i % 4 + (i % 4 == 0));
				if (a >= 0 && b >= 0 && b <= a) {
					win = (win + c[a][b] + MOD) % MOD;
				}
			}
		}

		i64 tot = c[n][n / 2];
		i64 lose = (tot - win - 1 + MOD) % MOD;
		cout << win << ' ' << lose << ' ' << 1 << '\n';
	}

	return 0;
}
