#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		int minDiff = INT_MAX;
		for (int l = 1; l <= n; ++l) {
			for (int w = 1; w <= m; ++w) {
				int peri = 2 * (l + w);
				int diff = abs(peri - k);
				minDiff = min(minDiff, diff);
			}
		}

		cout << minDiff << el;
	}

	return 0;
}
