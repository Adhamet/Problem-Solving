#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

struct comp {
	int s, e, u, i;
	int compL, compR;
};

int32_t main() {
	ios_base::sync_with_stdio(0),	cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<comp> cmp(n);
	set<int> coords;
	for (int i = 0; i < n; ++i) {
		cin >> cmp[i].s >> cmp[i].e >> cmp[i].u;
		cmp[i].i = i + 1;
		coords.insert(cmp[i].s);
		coords.insert(cmp[i].e);
	}

	map<int, int> compress;
	int cid = 0;
	for (auto &x: coords) compress[x] = cid++;
	for (auto& c : cmp) {
		c.compL = compress[c.s];
		c.compR = compress[c.e];
	}

	sort(cmp.begin(), cmp.end(), [](auto& a, auto& b) {
		return a.e < b.e;
	});

	int m = cid;
	vector<pair<i64, i64>> mem(m + 1, {-1, -1});

	vector<vector<int>> endsAt(m + 1);
	for (int i = 0; i < n; ++i)
		endsAt[cmp[i].compR].push_back(i);

	function<pair<i64, i64>(int)> go = [&](int idx) -> pair<i64, i64> {
		if (idx == 0) return {0, 0};

		auto &ret = mem[idx];
		if (ret.first != -1) return ret;

		auto take = go(idx - 1);
		for (auto &cmpIdx: endsAt[idx]) {
			auto &c = cmp[cmpIdx];
			auto prv = go(c.compL);
			pair<i64, i64> curr = {prv.first + c.u, prv.second - (c.e - c.s)};
			if (curr > take) take = curr;
		}

		return ret = take;
	};

	vector<int> plan;
	function<void(int)> build = [&](int idx) {
		if (idx == 0) return;

		auto take = go(idx - 1);
		for (int cmpIdx : endsAt[idx]) {
			auto &c = cmp[cmpIdx];
			auto prv = go(c.compL);
			pair<i64, i64> curr = {prv.first + c.u, prv.second - (c.e - c.s)};
			if (curr == mem[idx]) {
				build(c.compL);
				plan.push_back(c.i);
				return;
			}
		}

		build(idx - 1);
	};

	auto ans = go(m);		build(m);
	cout << (int)plan.size() << ' ' << ans.first << ' ' << -ans.second << el;
	for (int &x: plan) cout << x << ' ';
	return 0;
}

