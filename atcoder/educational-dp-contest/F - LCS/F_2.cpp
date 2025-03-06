#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int n, m;
string s, t;
vector<vector<int>> mem;
int recurse(int i, int j) {
	if (i < 1 || j < 1) return 0;

	int &ret = mem[i][j];
	if (~ret) return ret;
	ret = 0;

	if (s[i - 1] == t[j - 1]) return ret = 1 + recurse(i-1, j-1);
	return ret = max(recurse(i-1, j), recurse(i, j-1));
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> s >> t;
	n = (int)s.size(), m = (int)t.size();
	mem.assign(n + 1, vector<int>(m + 1, -1));
	recurse(n, m);
	
	int i = n, j = m;
	string lcs;
	while (i > 0 && j > 0) {
		if (s[i - 1] == t[j - 1]) lcs += s[i - 1], i -= 1, j -= 1;
		else if (mem[i - 1][j] > mem[i][j - 1]) i -= 1;
		else j -= 1;
	}

	reverse(lcs.begin(), lcs.end());
	return cout << lcs, 0;
}
