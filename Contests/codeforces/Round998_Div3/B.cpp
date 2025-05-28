#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n,m; cin >> n >> m;

		map<int,int> cows;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int x; cin >> x;
				cows[x] = i+1;
			}
		}

		if (n == 1) {
			cout << 1 << el;
			continue;
		}

		bool acc = true;
		int last = -1;
		vector<int> perm;
		for (int x = 0, idx = 0; x <= m*n-1; ++x, idx++) {
			if (cows[x] != last) {
				if ((int)perm.size() < n) perm.push_back(cows[x]);
				else {
					idx %= n;
					if (cows[x] != perm[idx]) {
						acc = false;
						break;
					}
				}
				
				last = cows[x];
			} else {
				acc = false;
				break;
			}
		}

		if (acc) {
			for (int i = 0; i < (int)perm.size(); ++i)
				cout << perm[i] << ' ';
			cout << el;
		} else cout << -1 << el;
	}

	return 0;
}
