#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int32_t tc;
	cin >> tc;

	while (tc--) {
		string s;
		int32_t n, k;
		cin >> n >> k >> s;
		
		int32_t ans = n;

		vector<bool> vis(n);
		for (int32_t i = 0; i < (k + 1) / 2; ++i) {
			if (vis[i]) continue;

			vector<int32_t> freq(26, 0);
			int32_t tot = 0;

			for (int32_t j = i; j < n; j += k) {
				if (vis[j]) continue;

				vis[j] = true;
				freq[s[j] - 'a']++;
				tot += 1;

				int32_t mirrorIdx = n - j - 1;			
				if (mirrorIdx != j) {
					vis[mirrorIdx] = true;
					freq[s[mirrorIdx] - 'a']++;
					tot++;
				}
			}

			int32_t mostFreq = 0;
			for (int32_t f: freq) mostFreq = max(mostFreq, f);
			ans -= mostFreq;
		}

		cout << ans << el;
	}

	return 0;
}
