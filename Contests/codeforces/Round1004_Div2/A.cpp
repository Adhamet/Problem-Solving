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
		int x, y;
		cin >> x >> y;
		int diff = x - y + 1;
		if (diff >= 0 && diff % 9 <= 0) cout << "Yes" << el;
		else cout << "No" << el;
	}

	return 0;
}
