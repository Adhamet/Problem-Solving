#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, k;
	cin >> n >> k;
	if (k / 2 >= n) {
		cout << "YES" << el;
		for (int i = 0; i < n - 1; i++) cout << "1 ";
		cout << k - n + 1 << el << k / 2 << el;
	} else cout << "NO" << el;

	return 0;
}

