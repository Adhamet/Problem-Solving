#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int n;
vector<vector<int>> memo, height;
int recurse(int p, int idx) {
	if (idx == n) return 0;

	int &ret = memo[p][idx];
	if (~ret) return ret;
	ret = 0;

	if (p == 2)
		return ret = max(height[0][idx] + recurse(1, idx+1), height[1][idx] + recurse(0, idx+1));
	return ret = max(height[p][idx] + recurse(!p, idx+1), recurse(2, idx+1));
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	memo.assign(3, vector<int>(n, -1));
	height.assign(2, vector<int>(n));

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j)
			cin >> height[i][j];

	return cout << recurse(2, 0), 0;
}
