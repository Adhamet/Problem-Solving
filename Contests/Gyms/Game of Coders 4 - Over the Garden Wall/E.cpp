#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, k;	cin >> n >> m >> k;
	vector<vector<char>> g(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> g[i][j];

	string s;	cin >> s;
	set<char> st(s.begin(), s.end());
	vector<int> freq(26,0);
	for (int i = 0; i < k; ++i) freq[s[i]-'a']++;


	vector<vector<vector<int>>> pref(26, 
						vector<vector<int>>(n+1,
									vector<int>(m+1)));

	for (int c = 0; c < 26; ++c) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				pref[c][i][j] = pref[c][i-1][j] + pref[c][i][j-1] -
										pref[c][i-1][j-1];
				if (g[i-1][j-1] - 'a' == c) pref[c][i][j]++;
			}
		}
	}

	auto can = [&](int len) {
		for (int i = 1; i+len-1 <= n; ++i) {
			int ii = i + len - 1;
			for (int j = 1; j+len-1 <= m; ++j) {
				int jj = j + len - 1;
				bool acc = true;

				for (int k = 0; k < 26; ++k) {
					if (freq[k]==0) continue;
					int cnt = pref[k][ii][jj] - pref[k][i-1][jj]
							- pref[k][ii][j-1] + pref[k][i-1][j-1];
					if (cnt < freq[k]) {
						acc = false;
						break;
					}
				}

				if (acc) return true;
			}
		}
		return false;
	};

	int ans=-1;
	int l = 1, r = min(n, m);
	while (l <= r) {
		int md = (l + r) >> 1;
		if (can(md)) ans=md, r = md-1;
		else l = md+1;
	}

	return cout << (ans == -1? -1: ans*ans), 0;
}
