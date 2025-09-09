#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, m;	cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int mxEle = n + m;
		vector<int> cnt(mxEle + 1, 0), appear(mxEle + 1, -1);

		for (int i = 0; i < n; ++i) appear[a[i]] = 0;
		for (int i = 1; i <= m; ++i) { // simulate op process
			int idx, v;		cin >> idx >> v;
			idx--;

			if (~appear[a[idx]]) {
				cnt[a[idx]] += (i - appear[a[idx]]);
				appear[a[idx]] = -1;
			}

			appear[v] = i;
			a[idx] = v;
		}

		int sz = m + 1;
		for (int x = 1; x <= mxEle; ++x) if (~appear[x])
			cnt[x] += (sz - appear[x]), appear[x] = -1;

		i64 ans = 0;
		i64 totPairs = 1LL * sz * (sz - 1) / 2;
		for (int x = 1; x <= mxEle; ++x) {
			if (cnt[x] == 0) continue;
			i64 okCnt = sz - cnt[x];
			i64 okPairs = okCnt * (okCnt - 1) / 2;
			ans += (totPairs - okPairs);
		}

		cout << ans << '\n';
	}

	return 0;
}
