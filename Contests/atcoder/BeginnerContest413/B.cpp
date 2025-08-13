#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

void solve() {
	int n;	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) cin >> s[i];

	set<string> st;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) if (i != j) {
			string res = s[i] + s[j];
			st.insert(res);
		}
	}

	cout << (int)st.size();
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int _tc = 1;
	/*cin >> _tc;*/
	while (_tc--) {
		solve();
	}

	return 0;
}
