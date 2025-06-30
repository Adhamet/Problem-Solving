#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i64 n, m, q;	cin >> n >> m >> q;

	i64 g = __gcd(n, m);
	i64 nn = n / g;
	i64 mm = m / g;
	while (q--) {
		i64 sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		i64 grp1 = (sx == 1) ? (sy - 1) / nn: (sy - 1) / mm;
		i64 grp2 = (ex == 1) ? (ey - 1) / nn: (ey - 1) / mm;
		cout << (grp1 == grp2? "YES": "NO") << el;
	}

	return 0;
}
