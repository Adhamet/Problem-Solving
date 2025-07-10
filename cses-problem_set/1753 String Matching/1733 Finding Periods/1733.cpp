#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;	cin >> s;
	int n = (int)s.size();
	vector<int> z(n);		z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (i < r) z[i] = min(r - i, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] > r) l = i, r = i + z[i];
	}

	int sz = 0;
	for (int i = 1; i < n; ++i) if (z[i] != 0) {
		sz = i;
		break;
	}

	if (sz == 0) return 0;
	cout << sz << ' ';
	while (sz + sz < n) {
		sz += sz;
		cout << sz << ' ';
	}

	return cout << n, 0;
}
