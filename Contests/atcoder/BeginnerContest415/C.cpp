#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		string s;	cin >> s;

		s = "0" + s;
		vector<int> ok(1 << n, 0);
		ok[0] = 1;
		for (int i = 0; i < (1 << n); i++) if (ok[i]) {
			for (int j = 0; j < n; j++) if (!(i & (1 << j))){
				int msk = (i | (1 << j));
				if (s[msk] == '0') ok[msk] = 1;
			}
		}

		if(ok[(1 << n) - 1]) cout << "Yes" << el;
		else cout << "No" << el;
	}
	return 0;
}
