#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;	cin >> s;
	int n = (int)s.size();

	int l = 0, r = 0;
	vector<int> z(n);		z[0] = n;
	for (int i = 1; i < n; ++i) {
		if (i < r) z[i] = min(r - i, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] > r) l = i, r = i + z[i];
	}

	for (int i = 0; i < n; ++i) cout << z[i] << ' ';
	return 0;
}
