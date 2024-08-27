#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int l, r;
		cin >> l >> r;

		int i = 1, score = 0;
		while (i * 2 <= r) {
			i *= 2;
			score += 1;
		}
		cout << score << '\n';
	}

	return 0;
}
