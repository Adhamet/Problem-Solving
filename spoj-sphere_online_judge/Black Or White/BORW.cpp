#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define el '\n'

const int MAXN = 200;
int n;
vector<int> a;
vector<vector<vector<int>>> mem;

int recurse(int idx, int lb, int lw) {
	if (idx == n) return 0;

	int &ret = mem[idx][lb][lw];
	if (~ret) return ret;

	ret = 1 + recurse(idx + 1, lb, lw);
	if (a[idx] > lb) ret = min(ret, recurse(idx + 1, a[idx], lw));
	if (a[idx] < lw) ret = min(ret, recurse(idx + 1, lb, a[idx]));

	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	while (cin >> n && n != -1) {
		a.resize(n);

		map<int, int> mp;
		for (int i = 0; i < n; ++i) cin >> a[i], mp[a[i]] += 1;

		int compressor = 1;
		for (auto i = mp.begin(); i != mp.end(); ++i) i->second = compressor++;

		for (int i = 0; i < n; ++i) a[i] = mp[a[i]];

		mem.assign(n + 1, vector<vector<int>>(202, vector<int>(202, -1)));
		cout << recurse(0, 0, compressor) << el;
	}

	return 0;
}
