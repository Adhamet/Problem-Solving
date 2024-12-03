#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	// she will be happy on day 1x1, 3x3, 5x5, 7x7 ..etc..
	vector<int> possibilities;
	for (int i = 1; i <= 100; i++) {
		if (i % 2 != 0) possibilities.push_back(i*i);
	}

	int t;
	cin >> t;
	while (t--) {
		int n, x, tot = 0, happies = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			tot += x;
			for (int i = 0; i < possibilities.size(); i++) {
				if (possibilities[i] == tot) {
					happies += 1;
				} else if (possibilities[i] > tot) break;
			}
		}

		cout << happies << el;
	}

	return 0;
}
