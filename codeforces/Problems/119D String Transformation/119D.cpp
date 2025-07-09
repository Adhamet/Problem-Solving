#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

vector<int> zf(string &s) {
	int n = (int)s.size();
	int l = 0, r = 0;
	vector<int> z(n);		z[0] = n;
	for (int i = 1; i < n; ++i) {
		if (i < r) z[i] = min(r - i, z[i - l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
		if (i+z[i] > r) l = i, r = i+z[i];
	} return z;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string a, b;	getline(cin, a), getline(cin, b);
	int szb = (int)b.size(), sza = (int)a.size();
	string p = b + '\x01' + a;
	int n = szb + 1 + sza;

	vector<int> zv = zf(p);
	int l = -1, r = sza;
	for (int i = szb+1; i < n; ++i) {
		int mdLen = zv[i];
		if (mdLen == 0) continue;

		int ll = i - (szb + 1);
		int rr = ll + mdLen;

		int lll = ll - 1;
		int rrr = rr;
		if (lll < 0 || rrr >= sza) continue;

		string cur = a.substr(lll+1, rrr-lll-1);
		string nxt = a.substr(rrr);
		reverse(nxt.begin(), nxt.end());
		string prv = a.substr(0, lll+1);
		reverse(prv.begin(), prv.end());

		if (cur + nxt + prv == b) {
			if (lll > l || (lll==l && rrr < r)) {
				l = max(l, ll);
				r = min(r, rr);
			}
		}
	}

	if (l == -1) return cout << "-1 -1", 0;
	return cout << l << ' ' << r, 0;
}
