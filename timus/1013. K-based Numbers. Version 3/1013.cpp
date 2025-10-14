#include <bits/stdc++.h>
using i64 = long long;

i64 m;
inline i64 addm(i64 a, i64 b) { a+=b; if (a>=m) a-=m; return a; }
inline i64 mulm(i64 a, i64 b) { return (i64)((__int128)a * b % m); }

struct Mat {
	i64 a[2][2];
	Mat(bool ident = false) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				a[i][j] = (i == j && ident)? 1 % m: 0;
	}
	Mat(i64 aa, i64 ab, i64 ba, i64 bb) {
		a[0][0] = aa % m; a[0][1] = ab % m;
		a[1][0] = ba % m; a[1][1] = bb % m;
	}
	Mat operator*(const Mat &him) const {
		Mat prod = Mat();
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					prod.a[i][j] = addm(prod.a[i][j], mulm(a[i][k], him.a[k][j]));
		return prod;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 n, k;
	std::cin >> n >> k >> m;

	Mat base(k - 1, 1, k - 1, 0);
	i64 v0 = (k - 1) % m, v1 = 0;
	Mat res(true);

	i64 exp = n - 1;
	while (exp) {
		if (exp & 1) res = res * base;
		base = base * base;
		exp >>= 1;
	}

	i64 xN0 = addm(mulm(res.a[0][0], v0), mulm(res.a[1][0], v1));
	i64 xN1 = addm(mulm(res.a[0][1], v0), mulm(res.a[1][1], v1));
	
	i64 ans = addm(xN0, xN1);
	return std::cout << ans, 0;
}

