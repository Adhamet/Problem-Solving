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
		int a, b, c;
		cin >> a >> b >> c; // a - 1, abs(b - c)
		int time1st = a, time2nd;
		if (b > c) time2nd = b;
		else time2nd = abs(b - c) + c;

		if (time1st < time2nd) cout << 1 << el;
		else if (time1st > time2nd) cout << 2 << el;
		else cout << 3 << el;
	}

	return 0;
}
