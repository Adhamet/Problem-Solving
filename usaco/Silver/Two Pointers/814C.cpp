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

	int n, q;
	string g;
	cin >> n >> g >> q;

	while (q--) {
		int m;
		char color;
		cin >> m >> color;

		int l = 0, r = 0, koyomity = 0;
		while (l < n && r < n) {
			while (r < n) {
				if (g[r] != color) {
					if (m == 0) break;
					m -= 1;
				}

				r += 1;
			}

			koyomity = max(koyomity, r - l);
			if (g[l] != color) m += 1;

			l += 1;
		}
		cout << koyomity << el;
	}

	return 0;
}
