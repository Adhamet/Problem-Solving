#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	if (n == m && n == 1) cout << 1;
	else if ((m - 1) < (n - m)) {
		cout << m + 1;
	} else cout << m - 1;
	return 0;
}
