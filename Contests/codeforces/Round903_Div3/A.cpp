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
		int n, m;
		cin >> n >> m;

		string x, s;
		cin >> x >> s;

		ll cnt = 0;
		bool acc = true;

		while (x.find(s) == x.npos) {
			cnt += 1;
			x += x;

			if (x.length() > 100) {
				cout << -1 << el;
				acc = false;
				break;
			}
		}

		if (acc) cout << cnt << el;
	}

	return 0;
}	
