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
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		int cnt = 0;
		bool acc = true;
		for (int i = n - 2; i >= 0; i--) {
			while (a[i] >= a[i + 1]) {
				if (a[i] == 0) {
					acc = false;
					break;
				}

				a[i] /= 2;
				cnt++;
			}

			if (!acc) break;
		}

		if (acc) cout << cnt << el;
		else cout << -1 << el;
	}

	return 0;
}
