#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			pq.push(x);
		}

		cout << "TEST: " << pq.top();

		int minute = 0, items = 0;
		while (!pq.empty()) {
			if (pq.top() < minute) {
				items += 1;
				minute += 1;
			}

			pq.pop();
		}

		cout << items << el;
	}

	return 0;
}
