#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int l, r, x, a, b;
		cin >> l >> r >> x >> a >> b;

		if (a == b) cout << 0 << el;
		else if (abs(a - b) >= x) cout << 1 << el;
		else if (abs(r - b) >= x && abs(r - a) >= x ||
					abs(a - l) >= x && abs(b - l) >= x) cout << 2 << el;
		else if (abs(b - l) >= x && abs(r - a) >= x ||
					abs(a - l) >= x && abs(r - b) >= x) cout << 3 << el;
		else cout << -1 << el;
	}

	return 0;
}
