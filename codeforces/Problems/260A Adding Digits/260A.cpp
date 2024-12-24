#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int a, b, n;
	cin >> a >> b >> n;
	a *= 10;
	int res = a % b;
	int x = (-res + b) % b;
	if (x > 9) return cout << -1, 0;
	a += x;
	cout << a;
	for (int i = 0; i < n - 1; ++i) cout << '0';
	return 0;
}
