#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> b(n), p(n), pos(n), dist(n), wei(n);

		int root = -1;
		for (int i = 0; i < n; ++i) {
			cin >> b[i];	--b[i];
			if (b[i] == i) root = i;
		}

		for (int i = 0; i < n; ++i) {
			cin >> p[i];	--p[i];
			pos[p[i]] = i;
		}

		if (p[0] != root) {
			cout << -1 << '\n';
			continue;
		}

		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (b[i] != i && pos[b[i]] > pos[i]) {
				ok = false;
				break;
			}
		}

		if (!ok) {
			cout << -1 << '\n';
			continue;
		}

		dist[p[0]] = 0;
		for (int i = 1; i < n; ++i) dist[p[i]] = dist[p[i-1]] + 1;

		for (int i = 0; i < n; ++i) {
			if (i == root) wei[i] = 0;
			else wei[i] = dist[i] - dist[b[i]];
		}

		for (int i = 0; i < n; ++i) cout << wei[i] << ' ';
		cout << '\n';
	}

	return 0;
}
