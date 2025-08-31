#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		int k;
		cin >> s >> k;
		int n = (int)s.size();
		
		vector<queue<int>> pos(10);
		for (int i = 0; i < n; ++i) pos[s[i] - '0'].push(i);

		int i = 0, j = 1;
		while (i < n && j <= n - k) {
			if (!pos[s[i] - '0'].empty()) pos[s[i] - '0'].pop();
			int mn = n;

			for (int d = (j == 1); d < s[i] - '0'; ++d)
				if (!pos[d].empty())
					mn = min(mn, pos[d].front());

			if (mn - i > k) {
				cout << s[i];
				i++, j++;
			} else {
				k -= (mn - i);
				while (++i < mn && i < n) 
					if (!pos[s[i] - '0'].empty())
						pos[s[i] - '0'].pop();
			}
		}

		cout << '\n';
	}

	return 0;
}

