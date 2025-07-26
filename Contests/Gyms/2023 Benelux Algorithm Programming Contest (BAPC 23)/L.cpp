#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<int> indeg(n), outdeg(n);
	for (int i = 0; i < m; ++i) {
		int u, v;	cin >> u >> v;
		indeg[v]++;
		outdeg[u]++;
	}

	int cnt = 0;
	for (int u = 0; u < n; ++u) if (indeg[u]) cnt += 1;
	return cout << cnt, 0;
}
