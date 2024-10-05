#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		ll n, m;
		cin >> n >> m;

		ll two = 0, five = 0, nn = n;
		while (n % 2 == 0) two++, n /= 2;
		while (n % 5 == 0) five++, n /= 5;

		ll mn = min(two, five);
		two -= mn, five -= mn;

		ll x = 1;
		while (two && x * 5 <= m) two--, x *= 5;
		while (five && x * 2 <= m) five--, x *= 2;
		while (x * 10 <= m) x *= 10;

		ll mx = x;
		for (int i = 1; i <= 9; i++) if (i * x <= m) {
			mx = max(mx, i * x);
		}

		cout << 1LL * nn * mx << el;
	}

	return 0;
}
