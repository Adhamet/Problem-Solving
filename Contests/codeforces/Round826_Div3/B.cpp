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
		int n;
		cin >> n;
		if (n == 3) {
			cout << -1 << el;
			continue;
		} else if (n == 2) {
			cout << "2 1" << el;
			continue;
		} else {
			cout << n << " " << n - 1 << " ";
			for (int i = 1; i <= n - 2; i++) cout << i << " ";
			cout << el;
		}
	}

	return 0;
}
