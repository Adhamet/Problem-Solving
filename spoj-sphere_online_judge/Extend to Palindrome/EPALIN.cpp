#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

vector<int> zf(string &s) {
	int n = (int)s.size();
	int l = 0, r = 0;
	vector<int> zv(n);	zv[0] = n;
	for (int i = 1; i < n; ++i) {
		if (i < r) zv[i] = min(r - i, zv[i - l]);
		while (i + zv[i] < n && s[zv[i]] == s[i + zv[i]]) ++zv[i];
		if (i + zv[i] > r) l = i, r = i + zv[i];
	} return zv;
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
		vector<int> zv = zf(p);
		int m = (int)p.size();

		bool acc = false;
		int mxZ = 0;
		for (int i = n + 1; i < m; ++i) if (m - i == zv[i]) {
			mxZ = zv[i];
			break;
		}

		string toAdd = s.substr(0, n - mxZ);
		reverse(toAdd.begin(), toAdd.end());
		cout << s + toAdd << el;
	}

	return 0;
}
