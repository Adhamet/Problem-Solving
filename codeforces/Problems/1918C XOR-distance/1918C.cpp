#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		i64 a, b, r, x = 0; cin >> a >> b >> r;
		if (a<b) swap(a,b);

		bool fst = false;
		for (i64 i = 60; i >= 0; --i) {
			i64 abit = a&(1LL<<i);
			i64 bbit = b&(1LL<<i);
			if (abit != bbit) {
				if (!fst) fst = true;
				else if (abit && x+(1LL<<i) <= r){
					x += (1LL << i);
					a ^= (1LL << i);
					b ^= (1LL << i);
				}
			}
		}

		cout << a - b << el;
	}

	return 0;
}
