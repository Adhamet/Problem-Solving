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
		int n;
		cin >> n;
		if (n < 11) cout << "NO" << el;
		else if (n < 100 && n % 11) cout << "NO" << el;
		else if (n % 11) {
			if (111 * (n % 11) <= n) cout << "YES" << el;
			else cout << "NO" << el;
		} else cout << "YES" << el;
	}

	return 0;
}
