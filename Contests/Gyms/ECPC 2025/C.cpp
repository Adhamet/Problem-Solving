#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr double EPS = 1e-9;

	int t;    cin >> t;
	while (t--) {
		i64 a, b, c;    cin >> a >> b >> c;
		if (c != 0) cout << -1 << el;
		else cout << fixed << setprecision(10) << double(a) / 2.0 << ' ' << double(b) / 2.0 << el;
	}

	return 0;
}

