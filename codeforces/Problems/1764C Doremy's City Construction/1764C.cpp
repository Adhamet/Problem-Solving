#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc;	cin >> tc;
	while (tc--) {
		int n;	cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		sort(a.begin(), a.end());
		if (a.front() == a.back()) {
			cout << (n / 2) << "\n";
			continue;
		}

		ll ans = 0;
		for (int l = 0, r; l < n; l = r) {
			r = l;
			while (r + 1 < n && a[r + 1] == a[l]) ++r;
			ans = max(ans, 1LL * (r+1) * (n - (r+1)));
			++r;
		}

		cout << ans << "\n";
	}

	return 0;
}
