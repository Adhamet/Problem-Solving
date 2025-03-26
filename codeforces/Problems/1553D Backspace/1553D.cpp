#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int32_t tc;
	cin >> tc;

	while (tc--) {
		string s, t;
		cin >> s >> t;

		if ((int)t.size() > (int)s.size()) {
			cout << "NO" << el;
			continue;
		}

		int i = (int)s.size() - 1, j = (int)t.size() - 1;
		int skips = 0;

		while (i >= 0) {
			if (skips > 0) skips -= 1, i -= 1;
			else {
				if (j >= 0 && s[i] == t[j]) i -= 1, j -= 1;
				else i -= 1, skips += 1;
			}
		}

		cout << (j == -1? "YES": "NO") << el;
	}

	return 0;
}
