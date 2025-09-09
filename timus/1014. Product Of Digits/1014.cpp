#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
     
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     
	int n;	cin >> n;
	if (n == 0) return cout << 10, 0;
	if (n == 1) return cout << 1, 0;
	
	vector<int> digits;
	for (int d = 9; d >= 2; --d) {
		while (n % d == 0) {
			digits.push_back(d);
			n /= d;
		}
	}

	if (n > 1) cout << -1;
	else {
		sort(digits.begin(), digits.end());
		for (auto &d: digits) cout << d;
	}

	return 0;
}
