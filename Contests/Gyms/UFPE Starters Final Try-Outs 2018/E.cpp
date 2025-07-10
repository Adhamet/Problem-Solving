#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;	cin >> s;
	int k;	cin >> k;
	
	int n = (int)s.size();
	i64 ans = 0;

	for (int i = 0; i < n; ++i){
		int mxR = min(i, n - i - 1);

		vector<int> pref(mxR + 1);
		pref[0] = 0;
		for (int r = 1; r <= mxR; ++r)
			pref[r] = pref[r - 1] + (s[i - r] != s[i + r]);

		int bestR = -1;
		for (int r = 0; r <= mxR && pref[r] <= k; ++r) bestR = r;
		if (bestR >= 0) ans += (bestR + 1);
	}

	for (int i = 0; i + 1 < n; ++i){
		int mxR = min(i, n - i - 2);
		if(mxR < 0) continue;

		vector<int> pref(mxR + 1);
		pref[0] = (s[i] != s[i + 1]);
		for (int r = 1; r <= mxR; ++r)
			pref[r] = pref[r - 1] + (s[i - r] != s[i + r + 1]);

		int bestR = -1;
		for (int r = 0; r <= mxR && pref[r] <= k; ++r) bestR = r;
		if (bestR >= 0) ans += (bestR + 1);
	}

	return cout << ans, 0;
}

