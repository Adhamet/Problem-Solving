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
		if (n <= 4) {
			cout << -1 << el;
			continue;
		} else if (n == 5) {
			cout << "3 1 5 4 2" << el;
			continue;
		} else if (n == 6) {
			cout << "3 1 5 4 2 6" << el;
			continue;
		}

		vector<int> evens, odds;
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 0 && i != 2) evens.push_back(i);
			else if (i % 2 != 0 && i != 3 && i != 7) odds.push_back(i);
		}

		cout << 3 << " ";
		for (int num: odds) cout << num << " ";
		cout << 7 << " " << 2 << " ";
		for (int num: evens) cout << num << " ";
		cout << el;
	}

	return 0;
}
