#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, k;	cin >> n >> m >> k;
	vector<array<int,2>> pts(k);
	unordered_map<int, int> cntX, cntY;

	int fX = 1e9, lX = 0, fY = 1e9, lY = 0;
	for (int i = 0; i < k; ++i) {
		cin >> pts[i][0] >> pts[i][1];
		cntX[pts[i][0]]++;
		cntY[pts[i][1]]++;
		fX = min(fX, pts[i][0]); // t7t
		lX = max(lX, pts[i][0]); // fo2
		fY = min(fY, pts[i][1]);
		lY = max(lY, pts[i][1]);
	}

	int ans = 0;
	array<int, 2> pt;
	for (int i = 0; i < n; ++i) {
		int curAns = 0;
		if (fX == pts[i][0])
			curAns = max(curAns, cntX[fX]);
		if (lX == pts[i][0])
			curAns = max(curAns, cntX[lX]);
		if (fY == pts[i][1])
			curAns = max(curAns, cntY[fY]);
		if (lY == pts[i][1])
			curAns = max(curAns, cntY[lY]);
		if (curAns > ans) {
			ans = curAns;
			pt = {pts[i][0], pts[i][1]};
		}
	}

	cout << ans << el << pt[0] << ' ' << pt[1];
	return 0;
}
