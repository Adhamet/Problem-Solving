#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<int> blocks;
	unordered_map<int, pair<int,int>> pos;  // x -> (tower, pos)

	for (int i = 0; i < n; ++i) {
		int k;	cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;	cin >> x;
			blocks.push_back(x);
			pos[x] = {i, j};
		}
	}

	sort(blocks.begin(), blocks.end());

	int leave = 0;
	for (int i = 0; i + 1 < (int)blocks.size(); ++i) {
		auto [t1, p1] = pos[blocks[i]];
		auto [t2, p2] = pos[blocks[i+1]];
		if (t1 == t2 && p2 == p1 + 1) ++leave;
	}

	int total = (int)blocks.size();
	int towers = total - leave;
	int splits = towers - n;
	int combines = towers - 1;

	return cout << splits << ' ' << combines, 0;
}

