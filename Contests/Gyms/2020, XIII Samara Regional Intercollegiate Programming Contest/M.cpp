#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<array<i64, 2>> tm(n);
	for (int i = 0; i < n; ++i) cin >> tm[i][0] >> tm[i][1];

	i64 secs = 0;
	for (int i = 0; i < n; ++i) {
		i64 t = tm[i][0], d = tm[i][1];
		if (t >= secs) secs = t + d;
		else secs += d;
	}

	return cout << secs, 0;
}

