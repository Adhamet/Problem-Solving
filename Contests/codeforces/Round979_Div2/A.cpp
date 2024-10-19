#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fst first
#define scd second
#define el '\n'
#define MOD 1000000007

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int MAXN = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int mn = 1e9, mx = 0;
		vector<int> a(n);
		for (auto &i: a) cin >> i, mn = min(mn, i), mx = max(mx, i);
		cout << (mx - mn) * (n - 1) << el;
	}

	return 0;
}
