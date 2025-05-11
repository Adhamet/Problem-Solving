#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, ele;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			a[i] = abs(a[i]);
		}

		int cnt = 0;
		for (int i = 1; i < n; ++i) if (a[i] < a[0]) cnt += 1;
		if (cnt <= (n/2)) cout << "YES" << el;
		else cout << "NO" << el;
	}

	return 0;
}
