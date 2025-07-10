#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n);
		
		bool acc = false;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] <= 1) acc = true;
		}

		cout << (acc? "YES": "NO") << el;
	}

	return 0;
}
