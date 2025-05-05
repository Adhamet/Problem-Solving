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
		int n;
		cin >> n;
		if (n % 2 == 0) {
			int even = (n * n) / 4 + 1;
			cout << even << el;
		} else {
			int odd = (n * n + 3) / 4;
			cout << odd << el;
		}
	}

	return 0;
}
