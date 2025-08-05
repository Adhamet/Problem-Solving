#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		i64 n, l, r, ans;		cin >> n >> l >> r;
		if (l == 1) ans = n / (r+1);
		else ans = n + (n / (r+1)) - (n / (l-1)) + (n%(l-1)? 0: 1);
		cout << ans << el;
	}

	return 0;
}
