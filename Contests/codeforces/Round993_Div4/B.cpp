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
		string s;
		cin >> s;
		reverse(s.begin(), s.end());

		int n = s.size();
		for (int i = 0; i < n; i++) {
			if (s[i] == 'p') s[i] = 'q';
			else if (s[i] == 'q') s[i] = 'p';
		}

		cout << s << el;
	}

	return 0;
}
