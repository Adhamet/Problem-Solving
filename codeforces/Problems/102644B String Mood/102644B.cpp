#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9+7;
inline i64 addm(i64 a, i64 b) { return (a += b) >= MOD? a - MOD: a; }
inline i64 subm(i64 a, i64 b) { return (a -= b) < 0? a + MOD: a; }

struct Mat {
	i64 a[2][2];
	Mat() {
		a[0][0] = a[0][1] = 0;
		a[1][0] = a[1][1] = 0;
	};
	Mat(i64 aa, i64 ab, i64 ba, i64 bb) {
		a[0][0] = aa, a[0][1] = ab;
		a[1][0] = ba, a[1][1] = bb;
	};
	Mat operator*(const Mat& him) {
		Mat prod = Mat();
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					prod.a[i][j] = addm(prod.a[i][j], (a[i][k] * him.a[k][j]) % MOD);	
		return prod;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 n;	std::cin >> n;

	// 5 flip, 2 sad, 1 happy, 18 nothing
	Mat base = Mat(19, 7, 6, 20);
	Mat res  = Mat(1, 0, 0, 1);

	i64 exp = n;
	while (exp) {
		if (exp & 1) res = res * base;
		base = base * base;
		exp >>= 1;
	}

	return std::cout << res.a[0][0] << '\n', 0;
}
