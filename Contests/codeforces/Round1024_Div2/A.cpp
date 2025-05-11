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
		int n, m, p, q, sum = 0;
		cin >> n >> m >> p >> q;
		bool acc = false;
		if (n%p == 0 && (m == (n/p)*q)) acc = true;
		else if (n%p != 0) acc = true;
		cout << (acc? "YES": "NO") <<el;
	}

	return 0;
}
