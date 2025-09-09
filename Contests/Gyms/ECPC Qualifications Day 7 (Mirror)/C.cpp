#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;   cin >> n >> m;

	vector<vector<char>> g(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin>>g[i][j];

	vector<bool> row(n, false), col(m, false);
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == '#') cnt+=1;
		}

		if (cnt == m) row[i] = true;
	}

	for (int j = 0; j < m; ++j) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (g[i][j] == '#') cnt += 1;
		}

		if (cnt == n) col[j] = true;
	}

	int mx = 0, mn = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (row[i] && col[j]) {
				mx += 1;
			}
		}
	}

	vector<bool> visI(n,false), visJ(m,false);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (row[i] && col[j] && !visI[i] && !visJ[j])
				mn++, visI[i] = visJ[j] = true;
		}
	}

	int notRow = 0, notCol = 0;
	for (int i = 0; i < n; ++i) if (!row[i]) notRow++;
	for (int j = 0; j < m; ++j) if (!col[j]) notCol++;
	if (notRow == n || notCol == m) return cout << 0 << ' ' << 0, 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (row[i] && col[j] && !visI[i])
				mn++, visI[i] = true;
			if (row[i] && col[j] && !visJ[j])
				mn++, visJ[j] = true;
		}
	}

	return cout << mx << ' ' << mn, 0;
}
