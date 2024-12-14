#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, r, d, a;
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> d >> a;
		if (d == 2 && r >= 1200 && r <= 2399) r += a;
		else if (d == 1 && r >= 1600 && r <= 2799) r += a;
	}

	cout << r << el;
	return 0;
}
