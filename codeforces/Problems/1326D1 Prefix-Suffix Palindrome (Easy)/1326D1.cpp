#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

bool isPali(string &s) {
	for (int i = 0, j = (int)s.size() - 1; i < j; ++i, --j)
		if (s[i] != s[j]) return false;
	return true;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		string s; cin >> s;
		int n = (int)s.size();

		int l = 0, r = n - 1;
		while (l < r && s[l] == s[r]) l++, r--;

		string mdl = s.substr(l, r-l+1);

		string best = "";
		for (int i = 0; i <= (int)mdl.size(); ++i) {
			string pref = mdl.substr(0, i);
			if (isPali(pref) && (int)pref.size()>(int)best.size())
				best = pref;
			
			string suff = mdl.substr(mdl.size() - i, i);
			if (isPali(suff) && (int)suff.size()>(int)best.size())
				best = suff;
		}

		cout << s.substr(0,l) + best + s.substr(r+1) << el;
	}

	return 0;
}

