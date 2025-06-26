#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int n, k;	
		string a, b;
		cin >> n >> k >> a >> b;

		int j = 0;
		vector<int> idx(26, -1);
		for (int i = 0; i < (int)a.size(); ++i) {
			if (idx[a[i]-'a']==-1) idx[a[i]-'a'] = j++;
		}

		i64 ans = 0;
		for (int msk = 0; msk < (1 << j); ++msk) {
			if (__builtin_popcount(msk) > k) continue;
			i64 curr = 0, cnt = 0;

			string aa = a;
			for (int i = 0; i < n; ++i) {
				if (a[i] != b[i] && msk & (1 << (idx[a[i] - 'a']))) {
					aa[i] = b[i];
				}

				if (aa[i] == b[i]) ++cnt;
				else {
					curr += (cnt * (cnt + 1) / 2);
					cnt = 0;
				}
			}

			if (cnt) curr += (cnt * (cnt + 1) / 2);
			ans = max(ans, curr);
		}

		cout << ans << el;
	}  return 0;
}
