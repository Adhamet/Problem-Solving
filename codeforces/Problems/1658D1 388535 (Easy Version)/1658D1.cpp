#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int cnt[32][2];
		memset(cnt, 0, sizeof cnt);

		int l, r;	cin >> l >> r;
		for (int i = l; i <= r; ++i) {
			int x;	cin >> x;
			for (int j = 0; j <= 30; ++j) {
				cnt[j][x & 1] += 1;
				x >>= 1;
			}
		}

		int ans = 0;
		for (int i = 0; i <= 30; ++i)
			ans |= ((cnt[i][0] < cnt[i][1]) * (1 << i));
		cout << ans << el;
	}  return 0;
}
