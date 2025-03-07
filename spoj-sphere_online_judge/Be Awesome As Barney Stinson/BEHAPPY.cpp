#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int gfs, gifts;
vector<vector<int>> mem;
vector<pair<int, int>> rng;

int recurse(int idx, int currgifts) {
	if (idx == gfs) return currgifts == 0 ? 1: 0;
	if (currgifts < 0) return 0;

	int &ret = mem[idx][currgifts];
	if (~ret) return ret;
	
	ret = 0;
	int ways = 0;
	for (int val = rng[idx].first; val <= rng[idx].second; ++val) if (currgifts - val >= 0) {
		ways += recurse(idx + 1, currgifts - val);
	}

	return ret = ways;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	while (cin >> gfs >> gifts) {
		if (gfs == 0 && gifts == 0) break;

		mem.assign(gfs, vector<int>(gifts + 1, -1));
		rng.resize(gfs);

		for (int i = 0; i < gfs; ++i) cin >> rng[i].first >> rng[i].second;
		cout << recurse(0, gifts) << el;
	}

	return 0;
}
