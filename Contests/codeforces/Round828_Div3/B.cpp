#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n, q;
		cin >> n >> q;
	
		int eCnt = 0, oCnt = 0;
		ll eSum = 0, oSum = 0;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			if (x % 2 == 0) eSum += x, eCnt += 1;
			else oSum += x, oCnt += 1;
		}

		while (q--) {
			int type, x;
			cin >> type >> x;
			if (type == 0) {
				if (x % 2 == 0) eSum += (x * eCnt);
				else {
					oSum += eSum + (x * eCnt);
					oCnt += eCnt;
					eSum = 0, eCnt = 0;
				}
			} else {
				if (x % 2 == 0) oSum += (x * oCnt);
				else {
					eSum += oSum + (x * oCnt);
					eCnt += oCnt;
					oSum = 0, oCnt = 0;
				}
			}

			cout << eSum + oSum << el;
		}
	}

	return 0;
}
