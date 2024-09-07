#include <algorithm>
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

	int n, k;
	cin >> n >> k;

	vector<ll> a(n);
	for (auto &i: a) cin >> i;

	while (k--) {
		ll x;
		cin >> x;

		auto itr = lower_bound(a.begin(), a.end(), x);		
		if (itr != a.end()) {
			cout << (itr - a.begin() + 1) << el;
		} else cout << n + 1 << el;
	}

	return 0;
}


