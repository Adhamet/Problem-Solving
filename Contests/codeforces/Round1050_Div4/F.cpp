#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	constexpr i64 P = 911382323, M1 = 1000000007, M2 = 1000000009;
	constexpr int MXN = 200000 + 5;

	std::vector<i64> pow1(MXN), pow2(MXN);
	pow1[0] = pow2[0] = 1;
	for (int i = 1; i < MXN; ++i) {
		pow1[i] = pow1[i - 1] * P % M1;
		pow2[i] = pow2[i - 1] * P % M2;
	}

	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::vector<std::vector<int>> a(n);
		int mxLen = 0;
		for (int i = 0; i < n; ++i) {
			int k; std::cin >> k;
			a[i].resize(k);
			for (int j = 0; j < k; ++j) std::cin >> a[i][j];
			mxLen = std::max(mxLen, k);
		}

		std::vector<std::vector<i64>> h1(n), h2(n);
		for (int i = 0; i < n; ++i) {
			int m = (int)a[i].size();
			h1[i].resize(m+1), h2[i].resize(m+1);
			for (int j = 0; j < m; ++j) {
				h1[i][j+1] = (h1[i][j] * P + a[i][j]) % M1;
				h2[i][j+1] = (h2[i][j] * P + a[i][j]) % M2;
			}
		}

		auto getHash = [&](int idx, int l, int r) -> std::pair<i64, i64> {
			i64 x = (h1[idx][r] - h1[idx][l] * pow1[r-l]) % M1;
			i64 y = (h2[idx][r] - h2[idx][l] * pow2[r-l]) % M2;
			if (x < 0) x += M1;
			if (y < 0) y += M2;
			return {x,y};
		};

		auto isBetter = [&](int i, int j, int lft) {
			int l = 0, r = std::min((int)a[i].size(), (int)a[j].size()) - lft;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (getHash(i, lft, lft+mid) == getHash(j, lft, lft+mid)) l = mid;
				else r = mid - 1;
			}
			if (lft + l == (int)a[i].size()) return true;
			if (lft + l == (int)a[j].size()) return false;
			return a[i][lft+l] < a[j][lft+l];
		};

		std::vector<int> ans;
		int l = 0;
		while (l < mxLen) {
			int curBest = -1;
			for (int i = 0; i < n; ++i) {
				if ((int)a[i].size() > l) {
					if (curBest == -1 || isBetter(i, curBest, l))
						curBest = i;
				}
			}
			for (int j = l; j < (int)a[curBest].size(); ++j)
				ans.push_back(a[curBest][j]);
			l = (int)a[curBest].size();
		}

		for (auto x: ans) std::cout << x << ' ';
		std::cout << '\n';
	}

	return 0;
}

