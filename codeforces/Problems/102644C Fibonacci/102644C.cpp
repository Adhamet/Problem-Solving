#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9+7;
inline i64 addm(i64 a, i64 b) { return (a += b) >= MOD? a - MOD: a; }
inline i64 subm(i64 a, i64 b) { return (a -= b) < 0? a + MOD: a; }

struct Mat2by1 {
	i64 ele[2][1];
	Mat2by1() { ele[0][0] = ele[1][0] = 0; };
	Mat2by1(i64 aa, i64 ba) { ele[0][0] = aa, ele[1][0] = ba; }
	Mat2by1 operator*(const Mat2by1& him) {
		Mat2by1 prod = Mat2by1();
		for (int i = 0; i < 2; ++i)
			for (int k = 0; k < 2; ++k)
				prod.ele[i][k] = addm(prod.ele[i][k], (ele[i][k] * him.ele[i][k]) % MOD);
		return prod;
	}
};

struct Mat2by2 {
	i64 ele[2][2];
	Mat2by2() { ele[0][0] = ele[0][1] = ele[1][0] = ele[1][1] = 0; };
	Mat2by2(i64 aa, i64 ab, i64 ba, i64 bb) {
		ele[0][0] = aa, ele[0][1] = ab;
		ele[1][0] = ba, ele[1][1] = bb;
	}
	Mat2by1 operator*(const Mat2by1& him) {
		Mat2by1 prod = Mat2by1();
		prod.ele[0][0] = addm(prod.ele[0][0], (ele[0][0] * him.ele[0][0]) % MOD);
		prod.ele[0][0] = addm(prod.ele[0][0], (ele[0][1] * him.ele[1][0]) % MOD);
		prod.ele[1][0] = addm(prod.ele[1][0], (ele[1][0] * him.ele[0][0]) % MOD);
		prod.ele[1][0] = addm(prod.ele[1][0], (ele[1][1] * him.ele[1][0]) % MOD);
		return prod;
	};
	Mat2by2 operator*(const Mat2by2& him) {
		Mat2by2 prod = Mat2by2();
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					prod.ele[i][j] = addm(prod.ele[i][j], (ele[i][k] * him.ele[k][j]) % MOD);
		return prod;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n;	std::cin >> n;

	Mat2by2 base = Mat2by2(0, 1, 1, 1);
	Mat2by1 res = Mat2by1(0, 1);
	i64 exp = n;
	while (exp) {
		if (exp & 1) res = base * res;
		base = base * base;
		exp >>= 1;
	}
	
	return std::cout << res.ele[0][0], 0;
}
