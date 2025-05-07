#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i32 tc;
	cin >> tc;

	while (tc--) {
		i32 n;
		cin >> n;

		vector<i32> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		i32 mxCnt = 0;
		for (int i = 0; i < n; ++i) {
			map<double, int> mp;

			i32 tmpCnt = 0;
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				double x = (double)(a[j] - a[i]) / (j - i);
				tmpCnt = max(tmpCnt, ++mp[x]);
			}

			mxCnt = max(mxCnt, tmpCnt + 1);
		}

		printf("%d\n", n - mxCnt);
	}

	return 0;
}
