#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 103;

int n, mem[MXN][1<<17], a[MXN];
vector<int> primeMsk(63);

int go(int idx, int msk) {
	if (idx == n) return 0;
	
	int &ret = mem[idx][msk];
	if (~ret) return ret;
	ret = 1e9;

	for (int x = 1; x <= 60; ++x) if ((msk & primeMsk[x]) == 0)
		ret = min(ret, abs(a[idx]-x) + go(idx+1, msk | primeMsk[x]));
	return ret;
}

void build(int idx, int msk) {
	if (idx == n) return;
	for (int x = 1; x <= 60; ++x) if ((msk & primeMsk[x]) == 0) {
		if (mem[idx+1][msk|primeMsk[x]] == mem[idx][msk]-abs(a[idx]-x)) {
			cout << x << ' ';
			build(idx+1, msk|primeMsk[x]);
			return;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	vector<int> primes = {2,3,5,7,11,13,17,19,23,29,
						31,37,41,43,47,53,59};
	for (int x = 1; x <= 60; ++x) {
		int curMsk = 0, y = x;
		for (int i = 0; i < (int)primes.size(); ++i) {
			if (y % primes[i] == 0) {
				curMsk |= (1 << i);
				while (y % primes[i] == 0) y /= primes[i];
			}
		}

		primeMsk[x] = curMsk;
	}

	memset(mem, -1, sizeof mem);
	for (int msk = 0; msk < (1<<17); ++msk) mem[n][msk] = 0;
	go(0,0);	build(0, 0);
	return 0;
}
