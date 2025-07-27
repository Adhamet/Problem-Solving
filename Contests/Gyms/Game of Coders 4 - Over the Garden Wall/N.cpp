#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;	cin >> n;
	int mxOd = -1, mxEv = -1;
	for (int i = 0; i < n; ++i) {
		int x;	cin >> x;
		if (x & 1) mxOd = max(mxOd, x);
		else mxEv = max(mxEv, x);
	}

	if (mxOd == -1 || mxEv == -1) return cout << -1, 0;
	return cout << mxOd+mxEv, 0;
}
