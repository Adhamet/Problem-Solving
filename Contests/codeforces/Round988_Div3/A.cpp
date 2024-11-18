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
		vector<int> a(n);
		for (auto &i: a) cin >> i;

		int ans = 0;
		vector<bool> vis(n, false);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] == a[j] && !vis[i] && !vis[j]) {
					ans += 1;
					vis[i] = true;
					vis[j] = true;
					break;
				}
			}
		}

		cout << ans << el;
	}

	return 0;
}
