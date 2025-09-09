#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

struct NODE {
	int l, r;
	int cnt2;
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<array<int, 2>> intervals;
		int i = 0;
		while (i < n) {
			int j = i;
			while (j < n && a[j] != 0) ++j;
			if (j == i) i += 1;
			else intervals.push_back({i, j}), i = j + 1;
		}

		NODE mx = {-1,-1,-1};
		for (auto &rng: intervals) { // 0 is avoided
			NODE toRmv = {-1,-1,-1};
			int curCnt2 = 0;
			bool sign = true, first = false;

			for (int i = rng[0]; i < rng[1]; ++i) {
				if (a[i] < 0) sign = !sign;
				if (abs(a[i]) == 2) curCnt2 += 1;
				if (!first && sign == false) toRmv = {rng[0],i,curCnt2}, first = true;
				if (sign == true && curCnt2 > mx.cnt2) mx = {rng[0],i,curCnt2};
			}

			if (sign == false && curCnt2 - toRmv.cnt2 > mx.cnt2)
				mx = {toRmv.r + 1, rng[1] - 1, curCnt2 - toRmv.cnt2};
		}

		if (mx.l == -1) cout << n << ' ' << 0 << '\n';
		else cout << ((mx.l-1) - 0 + 1) << ' ' << ((n - 1) - (mx.r+1) + 1) << '\n';
	}

	return 0;
}
