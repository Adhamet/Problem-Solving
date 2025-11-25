#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	std::vector<int> a(n), b(n);
	int cntAj[23] = {}, cntMai[23] = {};
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		for (int k = 0; k <= 20; ++k) cntAj[k] ^= ((a[i]>>k) & 1);
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
		for (int k = 0; k <= 20; ++k) cntMai[k] ^= ((b[i]>>k) & 1);
	}

	for (int i = 1; i <= n; ++i) {
		int ii = i - 1;
		if (i & 1) { // Aj
			for (int k = 0; k <= 20; ++k) {
				if (cntAj[k] & 1) continue;
				if (((a[ii]>>k) & 1) != ((b[ii]>>k) & 1)) {
					std::swap(a[ii], b[ii]);
					cntAj[k] ^= 1;
					cntMai[k] ^= 1;
				}
			}
		} else {
			for (int k = 0; k <= 20; ++k) {
				if (cntMai[k] & 1) continue;
				if (((a[ii]>>k) & 1) != ((b[ii]>>k) & 1)) {
					std::swap(a[ii], b[ii]);
					cntAj[k] ^= 1;
					cntMai[k] ^= 1;
				}
			}
		}
	}

	for (int k = 20; k >= 0; --k) {
		if (cntAj[k] > cntMai[k]) return void(std::cout << "Ajisai\n");
		else if (cntAj[k] < cntMai[k]) return void(std::cout << "Mai\n");
	}
	std::cout << "Tie\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
