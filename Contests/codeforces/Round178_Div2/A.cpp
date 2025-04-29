#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		c -= (b - a);
		a += (b - a);
		if (c >= a && c >= b) {
			c -= a;
			if (c % 3 == 0) cout << "YES" << el;
			else cout << "NO" << el;
		} else cout << "NO" << el;
	}

	return 0;
}
