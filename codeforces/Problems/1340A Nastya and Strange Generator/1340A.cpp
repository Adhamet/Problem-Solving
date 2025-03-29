#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int32_t> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<int32_t> p(n);
		iota(p.begin(), p.end(), 1);
		reverse(p.begin(), p.end());

		if (p == a) {
			cout << "Yes" << el;
			continue;
		}

		bool acc = true;
		for (int i = 0; i < n - 1; ++i) {
			if (a[i + 1] >= a[i] + 2) {
				acc = false;
				break;
			}
		}	

		cout << (acc? "Yes": "No") << el;
	}

	return 0;
}
