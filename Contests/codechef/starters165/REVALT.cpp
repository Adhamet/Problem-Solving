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
		int n;
		cin >> n;
		string s;
		cin >> s;

		int ones = 0, zeros = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') ones += 1;
			else zeros += 1;
		}

		if ((n&1) == 0 && zeros != (n>>1)) {
			cout << "No" << el;
			continue;
		} else if ((n&1) && (zeros != ((n - 1)>>1) && ones != ((n - 1)>>1))) {
			cout << "No" << el;
			continue;
		}

		string a = "", b = "";
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) a.push_back('1'), b.push_back('0');
			else a.push_back('0'), b.push_back('1');
		}

		int l = -1, r = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] != s[i]) {
				if (l == -1) l = i;
				r = i;
			}
		}

		if (l != -1) {
			string ss = s;
			reverse(ss.begin() + l, ss.begin() + r + 1);
			bool acc = true;
			for (int i = 0; i < n; i++) {
				if (ss[i] != a[i]) {
					acc = false;
					break;
				}
			}
			
			if (acc) {
				cout << "Yes" << el;
				continue;
			}
		} else {
			cout << "Yes" << el;
			continue;
		}

		l = -1, r = -1;
		for (int i = 0; i < n; i++) {
			if (b[i] != s[i]) {
				if (l == -1) l = i;
				r = i;
			}
		}

		if (l != -1) {
			string ss = s;
			reverse(ss.begin() + l, ss.begin() + r + 1);
			
			bool acc = true;
			for (int i = 0; i < n; i++) {
				if (ss[i] != b[i]) {
					acc = false;
					break;
				}
			}
			
			if (acc) {
				cout << "Yes" << el;
				continue;
			}
		} else {
			cout << "Yes" << el;
			continue;
		}

		cout << "No" << el;
	}

	return 0;
}
