#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

string s, t;
vector<vector<int>> mem;
int calc(int i, int j) {
	if (i < 0 || j < 0) return 0;
	int &ret = mem[i][j];
	if (~ret) return ret;
	ret = 0;
	if (s[i] == t[j]) return ret = calc(i - 1, j - 1) + 1;
	return ret = max(calc(i - 1, j), calc(i, j - 1));
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> s;
		t = s;
		reverse(t.begin(), t.end());

		int n = (int)s.size();
		mem.assign(n, vector<int>(n, -1));

		int lcs_size = calc(n-1, n-1);
		cout << n - lcs_size << el;
	}

	return 0;
}
