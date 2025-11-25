#include <bits/stdc++.h>

using i64 = long long;

const int MXN = 5000+3, MOD = 998244353;
inline i64 addm(i64 a, i64 b) { return (a += b) >= MOD? a - MOD: a; }

int n, rep[MXN][MXN];
i64 mem[MXN];
std::map<std::pair<int,int>,bool> mp;

i64 go(int idx) {
	if (idx >= n) return 1;

	if (~mem[idx]) return mem[idx];
	mem[idx] = 1;
	mp.clear();

	for (int i = idx; i < n; ++i) {
		i64 lhs = std::min(rep[idx][i], rep[i+1][n-1]);
		i64 rhs = std::max(rep[idx][i], rep[i+1][n-1]);
		if (!mp.count({lhs,rhs})) {
			i64 cur = lhs * rhs % MOD;
			mem[idx] = mem[idx] * ((go(i+1) * cur) % MOD) % MOD;
			mp[{lhs, rhs}] = 1;
		}
	}

	return mem[idx];
}

void solve() {
	std::cin >> n;
	std::fill(mem, mem+n, -1);
	int a[n];
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	int freq[5003], freqCnt[5003];
	for (int i = 0; i < n; ++i) {
		std::fill(freq, freq+5003, 0);
		std::fill(freqCnt, freqCnt+5003, 0);

		int mx = 0, cntMx = 0;
		for (int j = i; j < n; j++) {
			if (freq[a[j]]) freqCnt[freq[a[j]]]--;
			freq[a[j]]++;
			freqCnt[freq[a[j]]]++;

			if (freq[a[j]] > mx) mx = freq[a[j]], cntMx = 1;
			else if (freq[a[j]] == mx) cntMx++;

			rep[i][j] = cntMx;
		}
	}

	std::cout << go(0) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
