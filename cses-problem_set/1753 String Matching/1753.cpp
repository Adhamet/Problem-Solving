#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s, p;	cin >> s >> p;
	int szp = (int)p.size(), szs = (int)s.size();
	string t = p + '#' + s;
	int n = szp+szs+1;

	int l = 0, r = 0;
	vector<int> z(n);		z[0] = n;
	for (int i = 1; i < n; ++i) {
		if (i < r) z[i] = min(r - i, z[i - l]);
		while (i + z[i] < n && t[z[i]] == t[i + z[i]]) z[i]++;
		if (i + z[i] > r) l = i, r = i + z[i];
	}

	int cnt = 0;
	for (int i = szp + 1; i < n; ++i) if (z[i] >= szp) cnt += 1;
	return cout << cnt, 0;
}
