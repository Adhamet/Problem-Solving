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
		int a, b, c, x, y;
		cin >> a >> b >> c >> x >> y;

		bool acc = true;
		while (x) {
			if (a) {
				if (x - a <= 0) a -= x, x = 0;
				else x -= a, a = 0;
			} else if (c) {
				if (x - c <= 0) c -= x, x = 0;
				else x -= c, c = 0;
			} else {
				acc = false;
				break;
			}
		}

		while (y) {
			if (b) {
				if (y - b < 0) b -= y, y = 0;
				else y -= b, b = 0;
			} else if (c) {
				if (y - c < 0) c -= y, y = 0;
				else y -= c, c = 0;
			} else {
				acc = false;
				break;
			}
		}

		cout << (acc? "YES": "NO") << el;
	}

	return 0;
}
