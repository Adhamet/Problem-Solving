#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define fst first
#define scd second
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);

	double n, a, dx;
	while (cin >> n) {
		if (n == 0) break;
		int i = 0;
		while (++i) if (i * i * i > n) {
			a = i - 1;
			break;
		}

		dx = (n - (a*a*a)) / (3*a*a);
		cout << fixed << setprecision(4) << a + dx << el;
	}

	return 0;
}
