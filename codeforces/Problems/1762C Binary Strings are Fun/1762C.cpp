#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr i64 M = 998244353, MXN = 2e5+5;

	vector<i64> pw2(MXN);	pw2[0] = 1;
	for (int i = 1; i < MXN; ++i) pw2[i] = (pw2[i - 1] * 2) % M;
	
	int tc;	cin >> tc;
	while (tc--) {
		int n;	cin >> n;
		string s;	cin >> s;

		i64 ans = 0;
		int run = 0;
		for (int idx = 0; idx < n; ++idx) {
			if (idx == 0 || s[idx] != s[idx - 1]) run = 1;
			else run++;
			
			ans += pw2[run - 1];
			if (ans >= M) ans -= M;
		}

		cout << ans % M << "\n";
	}

	return 0;
}
