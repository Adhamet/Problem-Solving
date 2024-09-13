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
		int x;
		cin >> x;

		int a = x, b = 0;
		for (int i = 30; i >= 0; i--) {
			if (x & (1 << i)) continue;

			if (2 * x - a - b >= (2 << i)) {
				a += 1 << i, b += 1 << i;
			}
		}

		if (a + b == 2 * x && (a ^ b) == x) cout << a << " " << b << el;
		else cout << -1 << el;
	} 
}
