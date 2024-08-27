#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		ll cnt = 0;
		
		int i = n, op = 0;
		while (k > 0) {
			k -= i;
			cnt += 1;

			if (i == n) {
				i -= 1;
			} else {
				op += 1;
				if (op == 2) i -= 1, op = 0;
			}
		}
	
		cout << cnt << el;
	}

	return 0;
}
