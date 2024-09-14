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
		int l, r;
		cin >> l >> r;
	
		int odd = 0, even = 0;
		while (l <= r) {
			if (l % 2 == 1) odd += 1;
			else even += 1;

			l += 1;
		}

		int cnt = 0;
		while (even) {
			even -= 1;
			odd -= 2;
			cnt += 1;
		}

		cout << cnt << el;
	}

	return 0;
}
