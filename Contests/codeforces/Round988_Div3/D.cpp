#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define fst first
#define scd second
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k, end;
		cin >> n >> k >> end;

		vector<pair<int, int>> hurdles(n + 1), pwups(k + 1);
		for (int i = 1; i <= n; i++) cin >> hurdles[i].fst >> hurdles[i].scd;
		for (int i = 1; i <= k; i++) cin >> pwups[i].fst >> pwups[i].scd;

		bool acc = true;
		priority_queue<int> pq;
		ll idxP = 1, tot = 1, cnt = 0;
		for (int i = 1; i <= n; i++) {
			int h = hurdles[i].scd - hurdles[i].fst + 1;
			while (idxP <= k && pwups[idxP].fst < hurdles[i].fst) {
				pq.push(pwups[idxP].scd);
				idxP += 1;
			}

			while (tot <= h) {
				if (pq.empty()) {
					cout << -1 << el;
					acc = false;
					break;
				} else {
					int val = pq.top();
					pq.pop();
					tot += val;
					cnt += 1;
				}
			}

			if (!acc) break;
		}

		if (!acc) continue;
		cout << cnt << el;
	}

	return 0;
}
