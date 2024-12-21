#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'
#define MOD 1000000007

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int x, y, n;
	cin >> x >> y;
	cin >> n;
	
	x = (x % MOD + MOD) % MOD;
	y = (y % MOD + MOD) % MOD;
	int modRes = ((n - 1) % 6), ans;
	if (modRes == 0) ans = x;
	else if (modRes == 1) ans = y;
	else if (modRes == 2) ans = ((y - x) % MOD + MOD) % MOD;
	else if (modRes == 3) ans = ((-x) % MOD + MOD) % MOD;
	else if (modRes == 4) ans = ((-y) % MOD + MOD) % MOD;
	else if (modRes == 5) ans = ((-y + x) % MOD + MOD) % MOD;
	return cout << ans << el, 0;
}
