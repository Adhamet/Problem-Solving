#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9+7;
inline i64 addm(i64 a, i64 b) { return (a += b) >= MOD? a - MOD: a; }
inline i64 subm(i64 a, i64 b) { return (a -= b) < 0? a + MOD: a; }

struct Mat {
	i64 a[100][100];
	Mat() {
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				a[i][j] = 0;
	};
	Mat operator*(const Mat& him) {
		Mat prod = Mat();
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				for (int k = 0; k < 100; ++k)
					prod.a[i][j] = addm(prod.a[i][j], a[i][k] * him.a[k][j] % MOD);
		return prod;
	};
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n, m, k;
	std::cin >> n >> m >> k;

	Mat base = Mat();
	for (int i = 0, u, v; i < m; ++i) {
		std::cin >> u >> v;
		--u,--v;
		base.a[u][v] = 1;
	}
	Mat res;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (i == j) res.a[i][j] = 1;
			else res.a[i][j] = 0;
		}
	}

	i64 exp = k;
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9+7;
inline i64 addm(i64 a, i64 b) { return (a += b) >= MOD? a - MOD: a; }
inline i64 subm(i64 a, i64 b) { return (a -= b) < 0? a + MOD: a; }

struct Mat {
	i64 a[100][100];
	Mat() {
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				a[i][j] = 0;
	};
	Mat operator*(const Mat& him) {
		Mat prod = Mat();
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				for (int k = 0; k < 100; ++k)
					prod.a[i][j] = addm(prod.a[i][j], a[i][k] * him.a[k][j] % MOD);
		return prod;
	};
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n, m, k;
	std::cin >> n >> m >> k;

	Mat base = Mat();
	for (int i = 0, u, v; i < m; ++i) {
		std::cin >> u >> v;
		--u,--v;
		base.a[u][v] = 1;
	}
	Mat res;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (i == j) res.a[i][j] = 1;
			else res.a[i][j] = 0;
		}
	}

	i64 exp = k;
	while (exp) {
		if (exp & 1) res = res * base;
		base = base * base;
		exp >>= 1;
	}

	i64 ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ans = addm(ans, res.a[i][j]);
	return std::cout << ans, 0;
}
	while (exp) {
		if (exp & 1) res = res * base;
		base = base * base;
		exp >>= 1;
	}

	i64 ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ans = addm(ans, res.a[i][j]);
	return std::cout << ans, 0;
}
