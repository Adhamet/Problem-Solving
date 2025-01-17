#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;

		int bS = 0, bT = 0;
		for (char c : s) if (c == 'b') bS++;
		for (char c : t) if (c == 'b') bT++;
		if (bS != bT) {
			cout << "NO\n";
			continue;
		}

		int j = 0;
		bool valid = true;
		for (int i = 0; i < n && valid; i++) {
			if (s[i] == 'b') continue;

			while (j < n && t[j] == 'b') j++;

			if (j >= n || s[i] != t[j] || 
					(s[i] == 'a' && i > j) || 
					(s[i] == 'c' && i < j)) {
				valid = false;
				break;
			}
			j++;
		}

		cout << (valid ? "YES\n" : "NO\n");
	}

	return 0;
}
