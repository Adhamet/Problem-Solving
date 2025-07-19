#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr i64 oo = INT64_MAX;

	int n, m;
	while (cin >> n && n != 0) {
		cin >> m;

		vector<vector<array<i64,2>>> g(n+1);
		for (int i = 0; i < m; ++i) {
			int s, len;		cin >> s >> len;
			string op;		cin >> op;
			i64 k;		cin >> k;

			int a = s - 1, b = s + len - 1;
			if (op == "lt") g[a].push_back({b, k - 1});
			else g[b].push_back({a, -k - 1});
		}

		int nn = n + 1;
		bool negcyc = false;
		vector<i64> d(nn, 0);
		vector<i64> cnt(n, 0);
		vector<bool> inq(n, false);
		queue<int> q;
		for (int i = 0; i < nn; ++i)
			q.push(i), inq[i] = true;

		while (!q.empty() && !negcyc) {
			int u = q.front();	q.pop();
			inq[u] = false;

			for (auto &[v, w]: g[u]) if (d[u] + w < d[v]) {
				d[v] = d[u] + w;
				if (!inq[v]) {
					q.push(v);	inq[v] = true;
					if (++cnt[v] > nn) {
						negcyc = true;
						break;
					}
				}
			}
		}

		if (negcyc) cout << "successful conspiracy\n";
		else		cout << "lamentable kingdom\n";
	}

	return 0;
}
