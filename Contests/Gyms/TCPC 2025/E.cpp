#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

bool isSbsq(string &sbsq, string &s) {
	int idx = 0, n = (int)sbsq.size();
	for (auto &ch: s) if (idx<n && sbsq[idx]==ch) ++idx;
	return idx == n;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;	
	vector<string> s(n);
	for (int i = 0; i < n; ++i) cin >> s[i];

	set<string> csqs;
	int len = (int)s[0].size();
	for (int msk = 1; msk < (1 << len); ++msk) {
		string sbsq;
		for (int i = 0; i < len; ++i) if (msk & (1 << i))
			sbsq += s[0][i];
		if (isSbsq(sbsq, s[1]))
			csqs.insert(sbsq);
	}

	vector<string> csqv(csqs.begin(), csqs.end());
	sort(csqv.begin(), csqv.end(), [](auto &a, auto &b) {
		return (int)a.size()!=(int)b.size()? (int)a.size()>(int)b.size(): a < b;
	});

	for (string &sbsq: csqv) {
		bool ok = true;
		for (int i = 2; i < n; ++i) if (!isSbsq(sbsq, s[i])) {
			ok = false;
			break;
		}

		if (ok) return cout << sbsq, 0;
	}

	return cout << -1, 0;
}
