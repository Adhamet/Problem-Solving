#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, s1, s2;	cin >> n >> s1 >> s2;
		priority_queue<array<int,2>> pq;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			pq.push({x, i});
		}

		vector<int> a, b;
		int cs1 = s1, cs2 = s2;
		while (!pq.empty()) {
			if (cs1 <= cs2) { // put in container 1
				a.push_back(pq.top()[1]);
				pq.pop();
				cs1 += s1;
			} else { // put in container 2
				b.push_back(pq.top()[1]);
				pq.pop();
				cs2 += s2;
			}
		}

		cout << (int)a.size() << ' ';
		for (auto &idx: a) cout << idx + 1 << ' ';
		cout << '\n';
		cout << (int)b.size() << ' ';
		for (auto &idx: b) cout << idx + 1 << ' ';
		cout << '\n';
	}

	return 0;
}
