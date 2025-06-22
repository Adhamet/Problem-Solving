#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

/*
7
5 2 1 5 4
5 2 1 5 3
6 3 2 5 2
6 4 2 3 2
2 4 2 2 1
5 100 99 5 3
10 8 10 10 7
*/
const int MAXN = 1e8;
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		i64 n, wv, pv, wx, px;
		cin >> n >> wv >> pv >> wx >> px;
		int r = 0;
		for (int i = 0; i < MAXN; ++i) {
			if (wx < px) {
				if (px + pv > n) {
					int rem = pv - (n - px);
					if (rem%2==0) px = n;
					else px = n - 1;
					r += 1;

					if (wx == n - 1) {
						cout << r << el;
						break;
					}
				} else px = min(px+pv, n), r += 1;
			} else if (wx > px) {
				if (px - pv < 1) {
					int rem = pv - (px - 1);
					if (rem%2==0) px = 1;
					else px = 2;
					r += 1;

					if (wx == 2) {
						cout << r << el;
						break;
					}
				} else px = max(px-pv, i64(1)), r += 1;
			}

			i64 nwx;
			if (wx < px) nwx = min(wx + wv, n), r += 1;	
			else if (wx > px) nwx = max(wx - wv, i64(1)), r += 1;
			if ((wx < px && nwx >= px) || (wx > px && nwx <= px)) {
				cout << r << el;
				break;
			} else wx = nwx;
		}
	}

	return 0;
}
