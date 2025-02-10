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
		string s, t = "";
		cin >> s;

		int n = (int)s.size();
		if (s[n - 2] == 'u' && s[n - 1] == 's') {
			for (int i = 0; i < n - 2; ++i) {
				t += s[i];
			}

			t += 'i';
			cout << t << el;
		} else cout << s << el;
	}

	return 0;
}
