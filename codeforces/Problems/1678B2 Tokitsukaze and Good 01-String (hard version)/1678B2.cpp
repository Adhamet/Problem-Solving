#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define fst first
#define scd second
#define pi pair<int, int>
#define el '\n'

const int MAXN = 2e5+5, oo = 1e9;
int n;
string s;
pi mem[MAXN][3][3];

pair<int, int> solve(int idx, int z, int o) {
	if (idx == n) {
		if ((z+o) % 2 == 0) return {0, 0};
		return {oo, oo};
	}

	auto &res = mem[idx][z][o];
	if (~res.fst) return res;
	res = {oo, oo};

	auto update = [&](int cost, pair<int, int> nxt, bool newSeg = false) {
		cost += nxt.fst;
		int segs = nxt.second + newSeg;
		if (cost < res.fst || (cost == res.fst && segs < res.scd))
			res = {cost, segs};
	};

	if (z == 1) update(s[idx] != '0', solve(idx+1, 2, 0));
	else if (o == 1) update(s[idx] != '1', solve(idx+1, 0, 2));
	else if (z == 2) {
		update(s[idx] != '1', solve(idx+1, 1, 0));
		update(s[idx] != '0', solve(idx+1, 0, 1), true);
	} else if (o == 2) {
		update(s[idx] != '0', solve(idx+1, 0, 1));
		update(s[idx] != '1', solve(idx+1, 1, 0), true);
	} else {
		update(s[idx] != '1', solve(idx+1, 1, 0), true);
		update(s[idx] != '0', solve(idx+1, 0, 1), true);
	}

	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> n >> s;
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
					mem[i][j][k] = {-1, -1};

		pi res = solve(0, 0, 0);
		cout << res.fst << ' ' << res.scd << el;
	}

	return 0;
}
