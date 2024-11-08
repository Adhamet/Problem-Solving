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
		int n, sum = 0, steps = 0;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			while (x % 2 == 0) x /= 2, sum += 1;
			
			int y = i;
			while (y % 2 == 0) y /= 2, a[i] += 1;
		}

		sort(a.begin() + 1, a.end());
		for (int i = n; i >= 1 && sum < n; i--) {
			sum += a[i];
			steps += 1;
		}

		if (sum < n) cout << -1 << el;
		else cout << steps << el;
	}

	return 0;
}
