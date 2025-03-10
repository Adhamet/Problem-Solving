#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MAXN = 2005;
string s;
int32_t memo[MAXN][MAXN];

int32_t isPali(int l, int r) {
	if (l >= r) return 1;
	if (~memo[l][r]) return memo[l][r];
	return memo[l][r] = (s[l] == s[r]) && isPali(l + 1, r - 1);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> s;
	int32_t n = (int32_t)s.size();

	memset(memo, -1, sizeof memo);
	vector<int> diff(n, 0);

	string substr;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (isPali(i, j)) diff[i] += 1;
		}
	}

	for (int i = n - 1; i > 0; --i) diff[i - 1] += diff[i];

	int64_t ways = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i; j < n - 1; ++j) {
			if (isPali(i, j)) ways += diff[j + 1];
		}
	}

	return cout << ways, 0;
}
