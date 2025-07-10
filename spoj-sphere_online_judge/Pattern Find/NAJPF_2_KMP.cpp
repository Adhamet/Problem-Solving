#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

vector<int> kmp(string &s) {
	int n = (int)s.size();
	vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	} return pi;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		string a, b;	cin >> a >> b;
		int bsz = (int)b.size();
		string cmb = b + '#' + a;
		int k = (int)cmb.size();

		vector<int> pi = kmp(cmb), ans;
		for (int i = bsz + 1; i+bsz-1 < k; ++i) if (pi[i+bsz-1] == bsz)
			ans.push_back(i-bsz);

		if ((int)ans.size()) {
			cout << (int)ans.size() << el;
			for (auto &x: ans) cout << x << ' ';
			cout << el << el;
		} else cout << "Not Found\n" << el;
	}

	return 0;
}
