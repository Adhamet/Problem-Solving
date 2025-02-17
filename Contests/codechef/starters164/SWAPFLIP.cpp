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
		string s, t;
		cin >> n >> s >> t;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (s[i] != t[i] && s[j] != t[j] && s[i] == s[j] && t[i] == t[j]) {
					if (s[i] == '1') s[i] = '0', s[j] = '0';
					else if (s[i] == '0') s[i] = '1', s[j] = '1';
				} else if (s[i] != t[i] && s[j] != t[j] && s[i] != s[j] && t[i] != t[j]) {
					if (s[i] == '1') s[i] = '0', s[j] = '1';
					else if (s[i] == '0') s[i] = '1', s[j] = '0';
				}
			}
		}

		bool acc = true;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) acc = false;		
		}

		cout << (acc ? "YES": "NO") << el;
	}

	return 0;
}
