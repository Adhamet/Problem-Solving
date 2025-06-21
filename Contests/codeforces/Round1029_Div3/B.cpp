#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> ans(n);
		int j = 0, k = n - 1;
		for (int i = 0; i < n; ++i) {
			if (i%2==0) ans[j] = i+1, j+=1;
			else ans[k] = i+1, k-=1;
		}

		for (auto& x: ans) cout << x << ' ';
		cout << el;
	}

	return 0;
}
