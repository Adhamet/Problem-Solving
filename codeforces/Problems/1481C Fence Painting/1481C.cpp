#include <bits/stdc++.h>
using namespace std;

#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n), b(n), p(m);
		for (auto &i : a) cin >> i;
		for (auto &i : b) cin >> i;
		for (auto &i : p) cin >> i;

		vector<vector<int>> wants(n + 1), needs(n + 1);
		for (int i = 0; i < n; i++) {
			wants[b[i]].push_back(i);
			if (a[i] != b[i]) needs[b[i]].push_back(i);
		}

		if (wants[p.back()].empty()) {
			cout << "NO" << el;
			continue;
		}

		vector<int> ans(m, -1);
		for (int i = m - 1; i >= 0; i--) {
			if (!needs[p[i]].empty()) {
				ans[i] = needs[p[i]].back();
				needs[p[i]].pop_back();
			} else if (!wants[p[i]].empty()) {
				ans[i] = wants[p[i]].back();
			} else if (ans.back() != -1) {
				ans[i] = ans.back();
			}
		}

		bool acc = true;
		for (int i = 0; i <= n; i++) {
			if (!needs[i].empty()) {
				acc = false;
				break;
			}
		}

		if (!acc) {
			cout << "NO" << el;
		} else {
			cout << "YES" << el;
			for (auto num : ans) cout << num + 1 << " ";
			cout << el;
		}
	}

	return 0;
}
