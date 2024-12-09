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
		int n, x;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) {
			cin >> x;
			a[i] = x - a[i];
		}

		sort(a.begin(), a.end());
		int ans = 0, j = n - 1, i = 0;
		while (i < j) {
			if (a[i] + a[j] >= 0) ans += 1, i += 1, j -= 1;
			else {
				while (a[i] + a[j] < 0) i += 1;
				if (i < j) i += 1, j -= 1, ans += 1;
			}
		}

		cout << ans << el;
	}

	return 0;
}
