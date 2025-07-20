#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int oo = 1e9;

	string s, t;	cin >> s >> t;
	int n;	cin >> n;
	vector<vector<int>> d(26, vector<int>(26, oo));

	for (int i = 0; i < 26; ++i) d[i][i] = 0;

	for (int i = 0; i < n; ++i) {
		char c1, c2;	cin >> c1 >> c2;
		int w;		cin >> w;
		int u = c1 - 'a', v = c2 - 'a';
		d[u][v] = min(w, d[u][v]);
	}

	int m = (int)s.size();
	if (m != (int)t.size()) return cout << -1, 0;

	for (int k = 0; k < 26; ++k)
		for (int i = 0; i < 26; ++i)
			for (int j = 0; j < 26; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int sm = 0;
	string res = s;
	for (int i = 0; i < m; ++i) {
		int si = s[i] - 'a', ti = t[i] - 'a';
		if (si == ti) continue;

		int best = oo, bestChar = -1;
		for (int c = 0; c < 26; ++c) {
			if (d[si][c] < oo && d[ti][c] < oo) {
				int cost = d[si][c] + d[ti][c];
				if (cost < best) {
					best = cost;
					bestChar = c;
				}
			}
		}
	
		if (best == oo) return cout << -1, 0;
		sm += best;
		res[i] = char('a' + bestChar);
	}

	cout << sm << el << res << el;
}

