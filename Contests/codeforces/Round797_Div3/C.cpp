#include <bits/stdc++.h>
using namespace std;

#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n), b(n);
		for (auto &i: a) cin >> i;
		for (auto &i: b) cin >> i;

		int curr = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] >= curr) curr = a[i];

			cout << b[i] - curr << " ";
			curr = b[i];
		}
		cout << el;
	}

	return 0;
}
