#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k, itr;
		string s;
		cin >> n >> k >> s;

		int mx = s[0] - 'a', mxI = 0;
		for (itr = 0; itr < n; itr++) {
			if (s[itr] - 'a' >= k) break;
			if (s[itr] - 'a' > mx) {
				mx = s[itr] - 'a', mxI = itr;
			}
		}

		if (itr == n) {
			for (int i = 0; i < n; i++) cout << 'a';
			cout << el;
			continue;
		}

		if (itr == 0) {
			while (k--) {
				for (int i = n - 1; i >= 0; i--) if (s[i] == s[0]) {
					s[i] -= 1;
				}
			}

			for (int i = 0; i < n; i++) cout << s[i];
			cout << el;
			continue;
		}

		int toGo = k - mx;
		while (toGo--) {
			for (int i = 0; i < n; i++) {
				if (s[i] == s[itr] && i != itr) s[i] -= 1;
			}

			s[itr] -= 1;
		}

		for (int i = 0; i < n; i++) {
			if (s[i] - 'a' <= mx) s[i] = 'a';
		}

		for (int i = 0; i < n; i++) cout << s[i];
		cout << el;
	}

	return 0;
}
