#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, s;
		cin >> n >> s;

		vector<int> pref(n + 1);
		unordered_map<int, int> mp;

		for (int i = 1; i <= n; i++) cin >> pref[i];
		for (int i = 1; i <= n; i++) pref[i] += pref[i - 1];
		for (int i = 0; i <= n; i++) mp[pref[i]] = -1;

		int ans = 0;
		for (int i = 0; i <= n; i++) {
			if (mp[pref[i]] == -1) mp[pref[i]] = i;
			if (pref[i] >= s && mp[pref[i] - s] != -1) {
				ans = max(ans, i - mp[pref[i] - s]);
			}
		}

		cout << (ans ? n - ans : -1) << el;
	}

	return 0;
}
