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
		int n, sum = 0;
		cin >> n;
		
		int ans = n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];

		for (int i = 1; i <= n; i++) {
			sum += a[i];

			int res = i;
			bool acc = 1;
		
			int l = i + 1;
			while (l <= n) {
				int r = l, currSum = a[r];
				while (r + 1 <= n && currSum < sum) currSum += a[++r];

				if (currSum != sum) {
					acc = false;
					break;
				} else {
					res = max(res, r - l + 1);
					l = r + 1;
				}
			}

			if (acc) ans = min(ans, res);
		}

		cout << ans << el;
	}

	return 0;
}
