#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int n, x, y;
int dfs(int node) {
	if (node == 0) return 0;
	if (node == 1) return x;
	if (node % 2 != 0) return x + min(dfs(node + 1), dfs(node - 1));
	else return min(y, (node / 2) * x) + dfs(node / 2);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int ans = 0;
	cin >> n >> x >> y;
	if (n % 2 != 0) ans = x + min(dfs(n + 1), dfs(n - 1));
	else ans = dfs(n / 2) + min(x * (n / 2), y);
	return cout << ans << el, 0;
}
