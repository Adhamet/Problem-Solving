#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;

		vector<int> a(n);
		map<int,int> freq;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			freq[a[i]]+=1;
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (freq[a[i]] && freq[k-a[i]]) {
				if (a[i]==(k-a[i]) && freq[a[i]] < 1) continue;
				ans += 1;
				freq[a[i]]-=1;
				freq[k-a[i]]-=1;
			}
		}

		cout << ans << el;
	}

	return 0;
}
