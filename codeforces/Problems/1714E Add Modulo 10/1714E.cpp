#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define scd second
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		if (count(a.begin(), a.end(), a[0]) == n) {
			cout << "YES" << el;
			continue;
		}

		for (int i = 0; i < n; ++i) a[i] = (a[i] + (a[i] % 10));

		if (count(a.begin(), a.end(), a[0]) == n) {
			cout << "YES" << el;
			continue;
		}

		bool deny = false;
		for (int i = 0; i < n; ++i) if (a[i] % 10 == 0) {
			deny = true;
			break;
		}
		
		if (deny) {
			cout << "NO" << el;
			continue;
		}

		map<int, int> freq;
		for (int i = 0; i < n; ++i) {
			a[i] %= 20;
			for (int j = 0; j < 30; ++j) {
				freq[a[i]] += 1;
				a[i] = (a[i] + (a[i] % 10));
			}
		}

		bool found = false;
		for (auto &it: freq) if (it.scd == n) {
			found = true;
			break;
		}
		
		cout << (found? "YES": "NO") << el;
	}  return 0;
}
