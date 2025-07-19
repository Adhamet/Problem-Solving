#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, tc = 1;
	while (cin >> n && n) {
		unordered_map<string, int> currencyIdx;
		vector<vector<double>> rate(n, vector<double>(n, 0.0));

		for (int i = 0; i < n; ++i) {
			string currency;	cin >> currency;
			currencyIdx[currency] = i;
			rate[i][i] = 1.0;
		}

		int m;	cin >> m;
		for (int i = 0; i < m; ++i) {
			string from, to;
			double w;	cin >> from >> w >> to;
			int u = currencyIdx[from];
			int v = currencyIdx[to];
			rate[u][v] = w;
		}

		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					rate[i][j] = max(rate[i][j], rate[i][k]*rate[k][j]);

		bool arbitrage = false;
		for (int i = 0; i < n; ++i) if (rate[i][i] > 1.0) {
			arbitrage = true;
			break;
		}

		cout << "Case " << tc++ << ": ";
		cout << (arbitrage? "Yes": "No") << el;
	}

	return 0;
}
