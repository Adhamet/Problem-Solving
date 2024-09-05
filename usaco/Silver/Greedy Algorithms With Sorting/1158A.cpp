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

	int n, m;
	cin >> n >> m;

	ll res = 0;
	vector<int> b(n), g(m);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		res += b[i];
	}

	for (int i = 0; i < m; i++) cin >> g[i];
	res *= m;

	sort(b.begin(), b.end());
	sort(g.begin(), g.end());

	if (b[n - 1] > g[0]) {
		cout << -1;
		return 0;
	}

	for (int i = 1; i < m; i++) res += g[i] - b[n - 1];

	if (g[0] != b[n - 1]) res += g[0] - b[n - 2];
	cout << res << el;

	return 0;
}
