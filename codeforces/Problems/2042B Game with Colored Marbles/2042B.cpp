#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;
		vector<int> freq(1020, 0);
		for (int i = 0; i < n; i++) {
			cin >> x;
			freq[x] += 1;
		}

		ll tot = 0, ones = 0;
		for (int i = 0; i < 1002; i++) {
			if (freq[i] == 1) ones += 1;
			else if (freq[i] > 1) tot += 1;
		}

		if (ones % 2 != 0) tot += ((ones / 2) + 1) * 2;
		else tot += (ones / 2) * 2;
		cout << tot << el;
	}

	return 0;
}
