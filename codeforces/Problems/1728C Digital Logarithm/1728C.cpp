#include <bits/stdc++.h>
#include <queue>
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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		priority_queue<int> pqa(a.begin(), a.end());
		priority_queue<int> pqb(b.begin(), b.end());

		int ans = 0;
		while (!pqa.empty()) {
			if (pqa.top() == pqb.top()) {
				pqa.pop();
				pqb.pop();
				continue;
			}

			ans += 1;
			if (pqa.top() > pqb.top()) {
				pqa.push(to_string(pqa.top()).size());
				pqa.pop();
			} else {
				pqb.push(to_string(pqb.top()).size());
				pqb.pop();
			}
		}

		cout << ans << el;
	}

	return 0;
}
