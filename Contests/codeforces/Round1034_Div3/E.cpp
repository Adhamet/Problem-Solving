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
		for (int i = 0; i < n; i++) cin >> a[i];

		vector<int> freq(n + 2, 0);
		for (int i = 0; i < n; ++i) if (a[i] <= n) {
			freq[a[i]]++;
		}

		vector<bool> gotIt(n + 2, false);
		gotIt[0] = true;
		for (int x = 1; x <= n + 1; x++) {
			if (freq[x - 1] > 0) gotIt[x] = gotIt[x - 1];
			else gotIt[x] = false;
		}

		vector<int> diff(n + 3, 0);
		for (int x = 0; x <= n; x++) {
			if (!gotIt[x]) continue;
			if (freq[x] <= n - x) {
				diff[freq[x]]++;
				if (n - x + 1 < n + 3) diff[n - x + 1]--;
			}
		}

		int curr = 0;
		for (int k = 0; k <= n; k++) {
			curr += diff[k];
			cout << curr << ' ';
		} cout << el;
	}

	return 0;
}
