#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, d, m;
	cin >> n >> d >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;

		bool ok = true;
		if (!(x - y <= d && x - y >= -d)) ok = false;
		if (!(x + y <= n + n - d && (x + y) >= d)) ok = false;

		if (ok) cout << "YES" << el;
		else cout << "NO" << el;
	}

	return 0;
}
