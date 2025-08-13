#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

void solve() {
	int n, m;	cin >> n >> m;
	int tot = 0;
	for (int i = 0; i < n; ++i) {
		int x;	cin >> x;
		tot += x;
	}

	cout << (tot <= m? "Yes": "No");
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
