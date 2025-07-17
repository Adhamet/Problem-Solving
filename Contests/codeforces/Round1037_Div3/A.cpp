#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int x;
		cin >> x;

		vector<int> digits;
		while (x) {
			digits.push_back(x%10);
			x/=10;
		}

		cout << *min_element(digits.begin(), digits.end()) << el;
	}

	return 0;
}
