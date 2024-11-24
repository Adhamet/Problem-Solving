#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int a, b, aF[3] = {0}, bF[3] = {0};
	cin >> a >> b;
	
	if (a == b) {
		cout << 0;
	} else {
		while (a) {
			if (a % 2 == 0) {
				aF[0] += 1, a /= 2;
			} else if (a % 3 == 0) {
				aF[1] += 1, a /= 3;
			} else if (a % 5 == 0) {
				aF[2] += 1, a /= 5;
			} else break;
		}

		while (b) {
			if (b % 2 == 0) {
				bF[0] += 1, b /= 2;
			} else if (b % 3 == 0) {
				bF[1] += 1, b /= 3;
			} else if (b % 5 == 0) {
				bF[2] += 1, b /= 5;
			} else break;
		}

		if (a != b) cout << -1 << el;
		else cout << abs(aF[0] - bF[0]) + abs(aF[1] - bF[1]) + abs(aF[2] - bF[2]);
	}

	return 0;
}
