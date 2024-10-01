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

	ll n, q;
	cin >> n >> q;

	ll tot = 0;
	map<ll, ll> mp;
	vector<ll> a(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i], mp[i] = a[i], tot += a[i];

	ll lst = -1; 
	while (q--) {
		int op;
		cin >> op;
	
		if (op == 1) {
			ll idx, x;
			cin >> idx >> x;
			
			if (mp.count(idx)) {
				tot += (x - mp[idx]);
				mp[idx] = x;
			} else {
				tot += (x - lst);
				mp[idx] = x;
			}
		} else if (op == 2) {
			ll val; 
			cin >> val;
			
			tot = 1LL * n * val;
			mp.clear();
			lst = val;
		}

		cout << tot << el;
	}

	return 0;
}
