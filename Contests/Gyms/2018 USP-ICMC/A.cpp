#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	i64 n, k;	cin >> n >> k;
	i64 m = n - 1; // num of edges
	if (n == 1) cout << 0, 0;
	else if (n == 2) cout << k, 0;
	else cout << (m - gcd(n, k) + 1) * k + (gcd(n,k) - 1) * (k - 1) << el;
	return 0;
}
