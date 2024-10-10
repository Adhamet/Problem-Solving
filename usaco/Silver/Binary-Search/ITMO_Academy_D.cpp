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

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &i: a) cin >> i;
	sort(a.begin(), a.end());

	int k;
	cin >> k;

	while (k--) {
		int l, r;
		cin >> l >> r;

		auto v1 = upper_bound(a.begin(), a.end(), r);
		auto v2 = lower_bound(a.begin(), a.end(), l);
		cout << v1 - v2 << el;
	}

	return 0;
}
