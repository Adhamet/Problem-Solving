#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;	cin >> s;
	int n = (int)s.length();

	string t = s;

	bool place;
	place = false;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '.' && !place) {
			t[i] = 'o';
			place = true;
		}

		if (s[i] == '#') {
			place = false;
		}
	}

	return cout << t, 0;
}
