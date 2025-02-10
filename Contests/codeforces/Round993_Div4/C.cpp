#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m, a, b, c;
		cin >> m >> a >> b >> c;
		int row1 = m, row2 = m;

		int seatA = min(a, row1);
		row1 -= seatA;
		int seatB = min(b, row2);
		row2 -= seatB;
		int seatC1 = min(c, row1);
		c -= seatC1;
		int seatC2 = min(c, row2);

		cout << seatA + seatB + seatC1 + seatC2 << el;
	}

	return 0;
}
