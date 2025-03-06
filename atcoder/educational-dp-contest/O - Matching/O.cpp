#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MOD = 1e9+7;
int n;

vector<int> mem;
vector<vector<int>> couple;
int recurse(int man, int mask) {
	if (man == n) return 1;
	if (~mem[mask]) return mem[mask];

	int ways = 0;
	for (int woman = 0; woman < n; ++woman) {
		if (couple[man][woman] && !(mask & 1 << woman)) {
			ways = (ways + recurse(man + 1, (mask | (1 << woman)))) % MOD;
		}
	}

	return mem[mask] = ways;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	mem.assign(1 << n, -1);

	couple.assign(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> couple[i][j];

	return cout << recurse(0, 0), 0;
}
