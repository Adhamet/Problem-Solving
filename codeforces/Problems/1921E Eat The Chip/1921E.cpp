#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		ll h, w, xa, xb, ya, yb;
		cin >> h >> w >> xa >> ya >> xb >> yb;

		ll diff = xb - xa;
		if (diff < 0) {
			cout << "Draw\n";
			continue;
		}

		if (ya < yb) {
			if (diff % 2 == 0) {
				ya = max(1LL, ya - (diff + 1) / 2);
				yb = max(1LL, yb - diff / 2);
			} else {
				ya = min(w, ya + (diff + 1) / 2);
				yb = min(w, yb + diff / 2);
			}
		} else if (ya > yb) {
			if (diff % 2 == 1) {
				ya = max(1LL, ya - (diff + 1) / 2);
				yb = max(1LL, yb - diff / 2);
			} else {
				ya = min(w, ya + (diff + 1) / 2);
				yb = min(w, yb + diff / 2);
			}
		}

		if (ya == yb) {
			if (diff % 2 == 0) cout << "Bob\n";
			else cout << "Alice\n";
		} else cout << "Draw\n";
	}

	return 0;
}
