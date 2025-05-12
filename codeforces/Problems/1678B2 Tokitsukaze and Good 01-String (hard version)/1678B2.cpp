#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define pii pair<int,int>
#define fst first
#define scd second
#define el '\n'

const int MAXN = 2e5+5, oo = 1e9+7;
int n;
string s;
pii memo[MAXN][3][3];

pii solve(int idx, int z, int o) {
	if (idx == n) {
		if ((z + o) % 2 == 0) return {0, 0};
		return {oo, oo};
	}

	auto &ret = memo[idx][z][o];
	if (ret.fst != -1) return ret;
	ret = {oo, oo};

	auto update = [&](int cost, pii nxt, bool newSeg = false) {
		cost += nxt.first;
		int segs = nxt.second + newSeg;
		if (cost < ret.fst || (cost == ret.fst && segs < ret.scd))
			ret = {cost, segs};
	};

	if (z == 0 && o == 0) {
		update(s[idx] != '0', solve(idx + 1, 1, 0), true);
		update(s[idx] != '1', solve(idx + 1, 0, 1), true);
	} else if (z == 1) {
		update(s[idx] != '0', solve(idx + 1, 2, 0));
	} else if (o == 1) {
		update(s[idx] != '1', solve(idx + 1, 0, 2));
	} else if (z == 2) {
		update(s[idx] != '0', solve(idx + 1, 1, 0));
		update(s[idx] != '1', solve(idx + 1, 0, 1), true);
	} else if (o == 2) {
		update(s[idx] != '1', solve(idx + 1, 0, 1));
		update(s[idx] != '0', solve(idx + 1, 1, 0), true);
	}

	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
					memo[i][j][k] = {-1, -1};
		pii res = solve(0, 0, 0);
		cout << res.fst << ' ' << res.scd << el;
	}

	return 0;
}
