#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

constexpr u64 MOD = 4294967296;
inline u64 addm(u64 a, u64 b) { return (a += b) >= MOD? a - MOD: a; }

struct Mat {
	static constexpr int CN = 65;
	u64 a[CN][CN];
	Mat(bool ident = false) {
		for (int i = 0; i < CN; ++i)
			for (int j = 0; j < CN; ++j)
				a[i][j] = (ident && i == j);
	}

	static Mat zero() { return Mat(false); }
	static Mat identity() { return Mat(true); }

	const Mat operator*(const Mat& him) {
		Mat prod = Mat::zero();
		for (int i = 0; i < CN; ++i)
			for (int j = 0; j < CN; ++j)
				for (int k = 0; k < CN; ++k)
					prod.a[i][j] = addm(prod.a[i][j], a[i][k] * him.a[k][j] % MOD);
		return prod;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	auto inside = [](int r, int c) { return 0 <= r && r < 8 && 0 <= c && c < 8; };

	u64 k;	std::cin >> k;
	
	Mat base = Mat::zero();
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			for (int dr: {-2, -1, 1, 2}) {
				for (int dc: {-2, -1, 1, 2}) {
					if (abs(dr) != abs(dc)) {
						int nr = row + dr, nc = col + dc;
						if (inside(nr, nc)) base.a[8 * row + col][8 * nr + nc] = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i <= 64; ++i) base.a[i][64] = 1;

	Mat res = Mat::identity();
	k += 1;
	while (k) {
		if (k & 1) res = base * res;
		base = base * base;
		k >>= 1;
	}

	return std::cout << res.a[0][64], 0;
}
