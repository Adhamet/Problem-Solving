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
		vector<int> a(n), b, vis(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (!vis[a[i]]) b.push_back(a[i]);
			vis[a[i]] = 1;
		}

		for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
		for (int i = 1; i <= n; i++) if (vis[i] == 0) cout << i << " ";
		cout << el;
	}

	return 0;
}
