#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int oo = INT_MAX;

	int t;	cin >> t;
	while (t--) {
		int n, k;	cin >> n >> k;
		vector<array<int,2>> a(k);
		for (int i = 0; i < k; ++i) cin >> a[i][0], a[i][0]--;
		for (int i = 0; i < k; ++i) cin >> a[i][1];

		sort(a.begin(), a.end());

		vector<int> aff(n, oo);
		int wj = 0, lj = 1;	// working j, looping j
		for (int i = 0; i < n; ++i) {
			if (lj < k && a[lj][0] == i) {
				if (a[lj][1]+abs(a[lj][0]-i) <= a[wj][1]+abs(a[wj][0]-i)) 
					wj = lj;
				lj++;
			}
			aff[i] = a[wj][1] + abs(a[wj][0] - i);
		}

		wj = k - 1, lj = k - 2;
		for (int i = n - 1; i >= 0; --i) {
			if (lj >= 0 && a[lj][0] == i) {
				if (a[lj][1]+abs(a[lj][0]-i) <= a[wj][1]+abs(a[wj][0]-i)) 
					wj = lj;
				lj--;
			}
			aff[i] = min(aff[i], a[wj][1] + abs(a[wj][0] - i));
		}

		for (int i = 0; i < n; ++i) cout << aff[i] << ' ';
		cout << '\n';
	}

	return 0;
}
