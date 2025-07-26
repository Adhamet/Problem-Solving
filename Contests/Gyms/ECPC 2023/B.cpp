#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int M = 1e9+7;

	int t;	cin >> t;
	while (t--) {
		string s;	cin >> s;
		int n = (int)s.size();
		int mxLen = 0;

		vector<i64> cnt;
		for (int i = 0; i < n;) {
			int j = i;
			while (j < n && s[j]==s[i]) ++j;
			cnt.push_back(j - i);
			mxLen++;
			i = j;
		}

		i64 prod = 1;
		for (auto &x: cnt) prod = (prod * x) % M;
		cout << mxLen << ' ' << prod << el;
	}

	return 0;
}
