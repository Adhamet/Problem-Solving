#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	map<string, char> alphabet = {
		{"1", 'a'}, {"2", 'b'}, {"3", 'c'}, {"4", 'd'}, {"5", 'e'},
		{"6", 'f'}, {"7", 'g'}, {"8", 'h'}, {"9", 'i'}, {"10", 'j'},
		{"11", 'k'}, {"12", 'l'}, {"13", 'm'}, {"14", 'n'}, {"15", 'o'},
		{"16", 'p'}, {"17", 'q'}, {"18", 'r'}, {"19", 's'}, {"20", 't'},
		{"21", 'u'}, {"22", 'v'}, {"23", 'w'}, {"24", 'x'}, {"25", 'y'},
		{"26", 'z'}
	};

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s, ans = "";
		cin >> s;

		for (int i = n - 1; i >= 0; i--) {
			string str = "";
			if (s[i] == '0') {
				i -= 2;
				str += s[i];
				str += s[i + 1];
				ans += alphabet[str];
			} else {
				str += s[i];
				ans += alphabet[str];
			}
		}

		reverse(ans.begin(), ans.end());
		cout << ans << el;
	}

	return 0;
}
