#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int n, w;
vector<array<int, 2>> items;
vector<vector<int>> memo;
int recurse(int idx, int currw) {
	if (idx < 0) return 0;
	if (~memo[idx][currw]) return memo[idx][currw];
	if (currw + items[idx][0] <= w)	
		return memo[idx][currw] = max(recurse(idx - 1, currw), recurse(idx - 1, currw + items[idx][0]) + items[idx][1]);
	return memo[idx][currw] = recurse(idx - 1, currw);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> w;
	items.resize(n), memo.assign(n, vector<int>(w + 1, -1));
	for (int i = 0; i < n; ++i) cin >> items[i][0] >> items[i][1];
	return cout << recurse(n - 1, 0), 0;
}
