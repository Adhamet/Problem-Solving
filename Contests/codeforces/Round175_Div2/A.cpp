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
		int cycles = (n / 15), rem = n % 15;
		int ans = cycles * 3;
		for (int i = 0; i <= rem; ++i) if (i % 3 == i % 5) ans += 1;
		cout << ans << el;
	}

	return 0;
}

