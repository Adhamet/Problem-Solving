#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int ok(const string& s) {
	int cnt = 0;
	for (int i = 0; i + 6 < (int)s.size(); ++i) 
		if (s.substr(i, 7) == "abacaba") cnt++;
	return cnt;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		int n;
		string s;
		cin >> n >> s;

		bool acc = false;

		for (int i = 0; i <= n - 7; ++i) {
			string t = s;
			bool works = true;
			for (int j = 0; j < 7; ++j) {
				if (t[i + j] != '?' && t[i + j] != "abacaba"[j]) {
					works = false;
					break;
				}
			}

			if (!works) continue;

			for (int j = 0; j < 7; ++j)
				t[i + j] = "abacaba"[j];
			for (int j = 0; j < n; ++j)
				if (t[j] == '?') t[j] = 'z';

			if (ok(t) == 1) {
				cout << "Yes" << el;
				cout << t << el;
				acc = true;
				break;
			}
		}

		if (!acc) cout << "No" << el;
	}
	return 0;
}

