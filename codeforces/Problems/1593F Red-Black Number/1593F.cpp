#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 42, MXV = 1650;

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, A, B;	cin >> n >> A >> B;
		string s;	cin >> s;
		vector<i64> a(n);
		for (int i = 0; i < n; ++i) a[i] = (s[i] - '0');

		i64 dp[n+1][n+1][A][B];	// dp(idx)(cr)(rmA)(rmB);
		memset(dp, 0, sizeof dp);
		dp[0][0][0][0] = 1;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				for (int k = 0; k < A; ++k) {
					for (int l = 0; l < B; ++l) {
						if (dp[i][j][k][l]) {
							// red
							dp[i+1][j+1][(k*10+a[i])%A][l] = dp[i][j][k][l];
							// black
							dp[i+1][j][k][(l*10+a[i])%B] = dp[i][j][k][l] | (1ll << (i+1));
						}
					}
				}
			}
		}

		i64 msk = 0;
		int ans = 1e9;
		for (int i = 1; i < n; ++i) if (dp[n][i][0][0]) {
			if (abs(n - 2*i) < ans) {
				msk = dp[n][i][0][0];
				ans = abs(n - 2*i);
			}
		}

		if (ans == 1e9) cout << -1 << el;
		else {
			for (int i = 1; i <= n; ++i) {
				if ((msk>>i) & 1) cout << 'B';
				else cout << 'R';
			} cout << el;
		}
	}

	return 0;
}
