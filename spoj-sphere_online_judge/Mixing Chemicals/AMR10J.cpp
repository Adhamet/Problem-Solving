#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'
#define MOD 1000000007

const int MAXN = 205;
int n, k, nodes;
vector<int> c(MAXN), _factorial(MAXN), ways(MAXN), group(MAXN);
void init() {
	_factorial[0] = 1;
	for (int i = 1; i <= n; ++i) {
		_factorial[i] = _factorial[i - 1] * (k - 1) % MOD;
	}

	ways[1] = k, ways[2] = k * _factorial[1] % MOD;
	for (int i = 3; i <= n; ++i) {
		ways[i] = (k * _factorial[i - 1] % MOD - ways[i - 1] + MOD) % MOD;
	}

	for (int i = 1; i <= n; ++i) group[i] = 0;
}

void dfs(int node) {
	nodes += 1;
	node = c[node];
	if (group[node] > 0) {
		group[node] -= 1;
		if (group[node] == 0) {
			group[node] -= 1;
			dfs(node);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		init();
		for (int i = 1; i <= n; ++i) {
			cin >> c[i];
			c[i] += 1;
			group[c[i]] += 1;
		}

		nodes = 0;
		for (int i = 1; i <= n; ++i) if (group[i] == 0) {
			dfs(i);
		}

		int ans = _factorial[nodes];
		for (int i = 1; i <= n; ++i) if (group[i] == 1) {
			nodes = 0;
			group[i] -= 1;
			dfs(i);
			ans = ans * ways[nodes] % MOD;
		}

		cout << ans << el;
	}

	return 0;
}
