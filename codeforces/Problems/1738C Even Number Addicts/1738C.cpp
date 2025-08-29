#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

const int MXN = 102;

int mem[MXN][MXN][2][2];

bool go(int od, int ev, int parity, int turn) {
	if (od == 0 && ev == 0) return (parity == 0);

	int &ret = mem[od][ev][parity][turn];
	if (~ret) return ret;
	
	bool win;
	if (turn == 0) {
		win = false;
		if (od > 0) win |= go(od - 1, ev, parity ^ 1, 1);
		if (ev > 0) win |= go(od, ev - 1, parity, 1);
	} else {
		win = true;
		if (od > 0) win &= go(od - 1, ev, parity, 0);
		if (ev > 0) win &= go(od, ev - 1, parity, 0);
	}

	return ret = win;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		int od, ev;		od = ev = 0;
		for (int i = 0; i < n; ++i) {
			int x;	cin >> x;
			if (x % 2) od++;
			else ev++;
		}

		memset(mem, -1, sizeof mem);
		cout << (go(od, ev, 0, 0)? "Alice": "Bob") << '\n';
	}

	return 0;
}
