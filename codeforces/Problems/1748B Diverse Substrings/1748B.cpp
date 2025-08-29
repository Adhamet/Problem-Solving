#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'
#define debug(...)
/*#define debug(...) cerr << __VA_ARGS__ << el;*/

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		string s;	cin >> s;

		i64 ans = 0;
		for (int i = 0; i < n; ++i) {
			int cnt[10] = {0};
			int distinct = 0;
			int mxCnt = 0;
			int limit = min(n, i + 100);
			for (int j = i; j < limit; ++j) {
				int d = s[j] - '0';
				cnt[d]++;
				if (cnt[d] == 1) ++distinct;
				if (cnt[d] > mxCnt) mxCnt = cnt[d];
				if (mxCnt <= distinct) ++ans;
			}
		}

		cout << ans << el;
	}

	return 0;
}
