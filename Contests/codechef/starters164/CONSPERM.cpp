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
		int n;
		cin >> n;

		if (n % 2 == 0) {
			cout << -1 << el;
			continue;
		}

		vector<int> e, o;
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 0) e.push_back(i);
			else o.push_back(i);
		}

		sort(e.begin(), e.end(), greater<int>());
		int j = 0, k = 0;
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) ans[i] = o[k++];
			else ans[i] = e[j++];
		}

		for (int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << el;
	}

	return 0;
}
