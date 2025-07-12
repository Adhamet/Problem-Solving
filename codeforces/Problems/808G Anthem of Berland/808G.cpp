#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

vector<int> kmp(string &s) {
	int k = (int)s.size();
	vector<int> pi(k);
	for (int i = 1; i < k; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	} return pi;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s, t; cin >> s >> t;
	int ssz = (int)s.size(), tsz = (int)t.size();
	string ns = s;

	int cnt = 0;
	vector<int> pi = kmp(t);
	int k = 0;
	for (int i = 0; i < ssz; ++i) {
		while (k > 0 && (ns[i] != t[k] && ns[i] != '?'))
			k = pi[k - 1];
		if (ns[i] == t[k] || ns[i] == '?')
			k++;
		if (k == tsz) {
			for (int j = 0; j < tsz; ++j)
				ns[i - tsz + 1 + j] = t[j];
			cnt++;
			k = pi[k - 1];
		}
	}

	return cout << cnt, 0;
}

