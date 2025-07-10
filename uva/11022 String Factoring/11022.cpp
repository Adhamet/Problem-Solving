#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 80;
string s;
int mem[MXN+5][MXN+5];

vector<int> zf(string &s) {
	int n = (int)s.size();
	int l = 0, r = 0;
	vector<int> z(n);		z[0] = n;
	for (int i = 1; i < n; ++i) {
		if (i < r) z[i] = min(r - i, z[i - l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
		if (i + z[i] > r) l = i, r = i+z[i];
	} return z;
}

int solve(int l, int r) {
	if (l > r) return 0;
	int &ret = mem[l][r];
	if (~ret) return ret;
	int n = r - l + 1;
	ret = n;

	for (int k = l; k < r; ++k)
		ret = min(ret, solve(l, k) + solve(k + 1, r));
	
	string t = s.substr(l, n);
	vector<int> zv = zf(t);
	for (int repLen = 1; repLen * 2 <= n; ++repLen) {
		if (n % repLen) continue;
		if (zv[repLen] >= n - repLen)
			ret = min(ret, solve(l, l + repLen - 1));
	}

	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	while (cin >> s && s != "*") {
		memset(mem, -1, sizeof mem);
		cout << solve(0, (int)s.size() - 1) << el;
	}	

	return 0;
}
