#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc;	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		vector<string> matrix;
		string line;	cin >> line;
		int n = (int)line.size();
		matrix.push_back(line);
		for (int i = 1; i < n; ++i)
			cin >> line, matrix.push_back(line);

		vector<vector<bool>> f(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (matrix[i][j] == 'Y')
					f[i][j] = 1;

		vector<vector<bool>> nf(n, vector<bool>(n, false));
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) if (i != k) {
				for (int j = 0; j < n; ++j) if (j != k) {
					nf[i][j] = nf[i][j] | (f[i][k] & f[j][k]);
				}
			}
		}

		int idx = 0, cnt = 0;
		for (int i = 0; i < n; ++i) {
			int curCnt = 0;
			for (int j = 0; j < n; ++j) if (!f[i][j] && nf[i][j]) 
				curCnt += (i != j);
			if (curCnt > cnt) idx = i, cnt = curCnt;
		}

		cout << idx << ' ' << cnt << el;
	}

	return 0;
}
