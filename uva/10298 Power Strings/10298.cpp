#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

vector<int> kmpP(string &s) {
	int n = (int)s.size();
	vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) ++j;
		pi[i] = j;
	}

	vector<int> borders;
	for (int k = pi[n - 1]; k > 0; k = pi[k - 1]) borders.push_back(k);

	vector<int> periods;
	for (auto &b: borders) periods.push_back(n - b);
	return periods;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	while (cin >> s && s != ".") {
		int n = (int)s.size();
		vector<int> periods = kmpP(s);
		int mn = 1e7;
		for (auto &p: periods) if (n % p == 0) mn = min(mn, p);
		cout << (mn == 1e7? 1: n/mn) << el;
	} return 0;
}
