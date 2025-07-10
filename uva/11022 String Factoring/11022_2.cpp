#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 80+5;
string s;
int mem[MXN][MXN];

vector<int> kmpB(string &s) {
	int n = (int)s.size();
	vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) ++j;
		pi[i] = j;
	}

	vector<int> border;
	for (int k = pi[n - 1]; k > 0; k = pi[k - 1]) border.push_back(k);
	return border;
}

int solve(int l, int r) {
	if (l > r) return 0;
	
	int &ret = mem[l][r];
	if (~ret) return ret;
	ret = r - l + 1;

	for (int k = l; k < r; ++k)
		ret = min(ret, solve(l, k) + solve(k + 1, r));

	int len = r - l + 1;
	string t = s.substr(l, len);
	
	vector<int> border = kmpB(t);
	for (auto &b: border) {
		int p = len - b;
		if (len % p == 0) ret = min(ret, solve(l, l + p - 1));
	}

	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> s && s != "*") {
		memset(mem, -1, sizeof mem);
		cout << solve(0, (int)s.size() - 1) << el;
	} return 0;
}
