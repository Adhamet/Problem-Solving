#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int mod = 1e9+7;
vector<vector<char>> grid;
vector<vector<int>> memo;
int recurse(int x, int y) {
	if (x < 0 || y < 0 || grid[x][y] == '#') return 0;
	if (x == 0 && y == 0) return 1;
	if (~memo[x][y]) return memo[x][y];
	return memo[x][y] = (recurse(x - 1, y) + recurse(x, y - 1)) % mod;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	grid.assign(n, vector<char>(m));
	memo.assign(n, vector<int>(m, -1));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> grid[i][j];
	recurse(n - 1, m - 1);
	return cout << memo[n - 1][m - 1], 0;
}
