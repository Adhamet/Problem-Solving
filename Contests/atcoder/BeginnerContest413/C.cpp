#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

void solve() {
	int q;	cin >> q;
	deque<array<i64,2>> dq;
	while (q--) {
		int qry;	cin >> qry;
		if (qry == 1) {
			i64 c, x;	cin >> c >> x;
			dq.push_back({c,x});
		} else {
			i64 k;	cin >> k;
			i64 cursum = 0;
			while (!dq.empty() && k) {
				if (k >= dq.front()[0]) {
					cursum += dq.front()[0]*dq.front()[1];
					k -= dq.front()[0];
					dq.pop_front();
				} else {
					cursum += k*dq.front()[1];
					dq.front()[0] -= k;
					k = 0;
				}
			}

			cout << cursum << el;
		}
	}
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
