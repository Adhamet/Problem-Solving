#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		string s;
		cin >> s;

		int n = (int)s.size();
		int idx = -1;
		bool acc = false;
		for (int i = n - 1; i >= 0; --i) {
			if (s[i] != '0' && !acc) acc = true;
			if (s[i] == '0' && acc) {
				idx = i;
				break;
			}
		}

		if (acc && idx == -1) {
			if (n == 1) {
				cout << 0 << el;
				continue;
			} else {
				cout << n - 1 << el;
				continue;
			}
		}

		int num = 2;
		for (int i = idx - 1; i >= 0; --i) {
			if (s[i] == '0') num += 1;
		}

		cout << (int)s.size() - num << el;
	}

	return 0;
}
