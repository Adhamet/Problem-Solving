#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<int> pref(n, 0), suff(n,0);
		pref[0] = a[0], suff[n-1] = a[n-1];
		for (int i = 1; i < n; ++i)
			pref[i] = min(a[i], pref[i-1]);
		for (int i = n - 2; i >= 0; --i)
			suff[i] = max(a[i], suff[i+1]);

		map<int,bool> exist;
		for (int i = 0; i < n; ++i) {
			exist[pref[i]] = true;
			exist[suff[i]] = true;
		}

		string ans = "";
		for (int i = 0; i < n; ++i) {
			if (exist[a[i]]) ans += '1';
			else ans += '0';
		}

		cout << ans << el;
	}

	return 0;
}
