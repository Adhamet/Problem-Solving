#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		int lastIdx = 0, cnt = 0; // arbitrary index
		string t = s;	// I'll assume a spot with '1'.
		t[0] = '1';

		for (int i = 1; i < n; i++) {
			if (s[i] == '0') {
				cnt += 1;
				if (cnt > k) t[i] = '1', lastIdx = i, cnt = 0;
			} else {
				if (cnt < k) t[lastIdx] = '0';
				cnt = 0;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) if (t[i] != s[i]) ans += 1;
		cout << ans << el;
	}

	return 0;
}
