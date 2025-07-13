#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int kmp(string &s) {
	int n = (int)s.size();
	vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) ++j;
		pi[i] = j;
	} return pi[n - 1];
}

bool isPali(string &s) {
	int n = (int)s.size();
	int l = 0, r = n - 1;
	while (l <= r && s[l] == s[r]) l += 1, r -= 1;
	return l > r;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	while (cin >> s) {
		if (isPali(s)) {
			cout << s << el;
			continue;
		}

		int n = (int)s.size();
		string rs = s;
		reverse(rs.begin(), rs.end());
		string p = rs + '#' + s;
		int m = (int)p.size();
		int period = kmp(p);

		string toAdd = s.substr(0, n - period);
		reverse(toAdd.begin(), toAdd.end());
		cout << s + toAdd << el;
	}

	return 0;
}

