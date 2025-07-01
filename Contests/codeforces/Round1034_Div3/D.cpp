#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int n, k;	cin >> n >> k;
		string s;	cin >> s;
		int ones = count(s.begin(), s.end(), '1');
		if (ones <= k) {
			cout << "Alice\n";
			continue;
		} else {
			if (2 * k <= n) cout << "Bob" << el;
			else cout << "Alice" << el;
		}
	} return 0;
}
