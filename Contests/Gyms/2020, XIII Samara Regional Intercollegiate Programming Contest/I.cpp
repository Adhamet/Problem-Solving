#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<i64> last(n+50, -INT64_MAX);
	bool acc = true;
	for (int i = 0; i < n; ++i) {
		i64 v, c;	cin >> v >> c;
		if (v < last[c]) acc = false;
		last[c] = v;
	}

	return cout << (acc? "YES": "NO"), 0;
}
