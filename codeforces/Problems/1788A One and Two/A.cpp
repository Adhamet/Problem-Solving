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
		int n;
		cin >> n;

		ll sm = 0;
		vector<ll> a(n);
		for (auto &i: a) cin >> i, sm += i - 1;

		bool acc = false;
		ll k = sm;
		for (int i = 0; i < n; i++) {
			sm -= a[i] - 1;
			if (sm == k - sm) {
				cout << i + 1 << el;
				acc = true;
				break;
			}
		}

		if (!acc) cout << -1 << el;
	}

	return 0;
}
