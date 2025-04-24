#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		int cnt = 0;
		vector<vector<string>> vec;
		for (int i = 0; i < n; ++i) {
			string tmp = s;
			if (tmp[i] == '0') tmp[i] = '1';
			else tmp[i] = '0';
			for (int i = 0; i < n; ++i) if (tmp[i] == '1') cnt += 1;
		}

		cout << cnt << el;
	}

	return 0;
}
