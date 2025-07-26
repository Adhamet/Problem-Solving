#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<string> p(n);
	for (int i = 0; i < n; ++i) cin >> p[i];

	vector<string> org(n, string(m, '.'));
	const int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
	const int dy[] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool allBlack = true;
			for (int k = 0; k < 9; ++k) {
				int ni = i + dx[k], nj = j + dy[k];
				if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
					if (p[ni][nj] == '.') {
						allBlack = false;
						break;
					}
				}
			}
			if (allBlack) org[i][j] = '#';
		}
	}

	vector<string> p2(n, string(m, '.'));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool black = false;
			for (int k = 0; k < 9; ++k) {
				int ni = i + dx[k], nj = j + dy[k];
				if (ni >= 0 && ni < n && nj >= 0 && nj < m && org[ni][nj] == '#') {
					black = true;
					break;
				}
			}
			p2[i][j] = (black ? '#': '.');
		}
	}

	if (p2 == p) {
		cout << "Possible" << el;
		for (auto &s: org) cout << s << el;
	} else cout << "Impossible" << el;

	return 0;
}

