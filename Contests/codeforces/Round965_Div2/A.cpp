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
		ll x, y, k;
		cin >> x >> y >> k;

		for (int i = 0; i < (k / 2); i++) {
			cout << x - i - 1 << " " << y << el;
			cout << x + i + 1 << " " << y << el;
		}

		if (k % 2 == 1) cout << x << " " << y << el;
	}

	return 0;
}
