#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MOD = 998244353, MXN = 1005, MXK = 2005;

int n, k;
i64 mem[MXN][4][MXK];

i64 go(int idx, int pmsk, int cmpCnt) {
	if (idx == n) return (cmpCnt == k);

	i64 &ret = mem[idx][pmsk][cmpCnt];
	if (~ret) return ret;
	ret = 0;

	int pt = (pmsk >> 1) & 1, pb = pmsk & 1;
	for (int cmsk = 0; cmsk < 4; ++cmsk) {
		int ct = (cmsk >> 1) & 1;
		int cb = cmsk & 1;

		int nCmp = (ct == cb ? 1 : 2);
		int merged = 0;

		if (nCmp == 1) {
			if (ct == pt || cb == pb) merged = 1;
		} else {
			if (ct == pt) merged++;
			if (cb == pb) merged++;
		}

		ret = (ret + go(idx+1, cmsk, cmpCnt+(nCmp - merged))) % MOD;
	}

	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	memset(mem, -1, sizeof mem);
	i64 ans = 0;
	for (int msk = 0; msk < 4; ++msk) {
		int t = (msk >> 1) & 1;
		int b = msk & 1;
		int startCmp = (t == b ? 1 : 2);
		ans = (ans + go(1, msk, startCmp)) % MOD;
	} return cout << ans, 0;
}

