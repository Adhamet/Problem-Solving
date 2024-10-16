#include <bits/stdc++.h>
using namespace std;

const int MAXN = 250;
int n, m;
vector<int> depths(MAXN);
vector<vector<bool>> vis(MAXN, vector<bool>(MAXN));
vector<pair<int, int>> shoes(MAXN);

int ans = INT32_MAX;
void dfs(int depth, int boot) {
	if (vis[depth][boot]) return;

	vis[depth][boot] = true;
	if (depth == n - 1) {
		ans = min(boot, ans);
		return;
	}

	for (int i = depth + 1; i <= depth + shoes[boot].second && i < n; i++) {
		if (depths[i] <= shoes[boot].first) dfs(i, boot);
	}

	for (int i = boot; i < m; i++) if (depths[depth] <= shoes[i].first) {
         dfs(depth, i); 
    }
}

int main() {
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)  cin >> depths[i]; 
	for (int i = 0; i < m; i++) cin >> shoes[i].first >> shoes[i].second;
	dfs(0, 0);
	cout << ans << "\n";
}
