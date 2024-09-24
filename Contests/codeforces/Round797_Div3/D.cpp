#include <bits/stdc++.h>
using namespace std;

#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;

		int cnt = 0;
		for (int i = 0; i < k; i++) if (s[i] == 'W') {
			cnt += 1;
		}

		int ans = cnt, l = 1, r = k;
		while (r < n) {
			if (s[l - 1] == 'W') cnt -= 1;
			if (s[r] == 'W') cnt += 1;

			ans = min(ans, cnt);
			l += 1, r += 1;
		}
		
		cout << ans << el;
	}

	return 0;
}
