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

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;	cin >> s;
	int n = (int)s.size(), len = 0;
	vector<int> zv = zf(s);
	vector<int> cnt(n + 1);
	for (int j = 1; j < n; ++j) cnt[zv[j]]++;
	for (int k = n - 1; k >= 1; --k) cnt[k] += cnt[k + 1];
	for (int i = 1; i < n; ++i) if (zv[i] == n - i && cnt[zv[i]] >= 2)
			len = max(len, zv[i]);
	return cout << (!len? "Just a legend": s.substr(0, len)), 0;
}
