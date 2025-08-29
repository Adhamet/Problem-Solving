#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i64 n;	cin >> n;
	i64 l = 3, r = 1e13, ans = -1;
	while (l <= r) {
		i64 md = (l + r) >> 1;
		i64 equ = (md - 1) / 2 + max(i64(0), (md / 4 - 1));
		if (equ >= n) ans = md, r = md - 1;
		else l = md + 1;
	}

	return cout << ans, 0;
}
