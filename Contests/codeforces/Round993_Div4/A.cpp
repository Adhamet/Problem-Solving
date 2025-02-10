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
		int n, cnt = 0;
		cin >> n;
		for (int i = 1; i <= 300; i++) {
			for (int j = 1; j <= 300; j++) {
				if (i == (n - j)) cnt += 1;
			}
		}

		cout << cnt << el;
	}

	return 0;
}
