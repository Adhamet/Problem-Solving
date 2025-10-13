#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 oo = (1LL << 60);
struct Mat {
	static constexpr int CN = 100;
	i64 a[CN][CN];

	Mat(bool ident = false) {
		for (int i = 0; i < CN; ++i)
			for (int j = 0; j < CN; ++j)
				a[i][j] = (ident && i == j) ? 0: oo;
	}

	static Mat zero() { return Mat(false); }
	static Mat identity() { return Mat(true); }

	Mat operator*(const Mat& him) const {
		Mat prod;
		for (int i = 0; i < CN; ++i) {
			for (int j = 0; j < CN; ++j) {
				i64 best = oo;
				for (int k = 0; k < CN; ++k)
					if (a[i][k] != oo && him.a[k][j] != oo)
						best = std::min(best, a[i][k] + him.a[k][j]);
				prod.a[i][j] = best;
			}
		}
		return prod;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	i64 k;
	std::cin >> n >> m >> k;

	Mat base;
	for (int i = 0; i < m; ++i) {
		int u, v;
		i64 w;
		std::cin >> u >> v >> w;
		--u; --v;
		base.a[u][v] = std::min(base.a[u][v], w);
	}

	Mat res = Mat::identity();
	while (k > 0) {
		if (k & 1) res = res * base;
		base = base * base;
		k >>= 1;
	}

	i64 ans = oo;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ans = std::min(ans, res.a[i][j]);

	if (ans == oo) std::cout << "IMPOSSIBLE\n";
	else std::cout << ans << '\n';

	return 0;
}

