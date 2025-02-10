#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
		vector<array<int, 3>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i][0] >> a[i][1];
			a[i][2] = i;
		}

		map<int, int> m;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (a[i][0] == a[i][1]) {
				if (!m[a[i][0]]) ans.push_back(a[i][0]);
				m[a[i][0]] += 1;
			}
		}
		
		sort(ans.begin(), ans.end());
		string res(n, '0');
		for (int i = 0; i < n; i++) {
			if (a[i][0] == a[i][1]) {
				if (m[a[i][0]] <= 1) res[a[i][2]] = '1';
			} else {
				int l = lower_bound(ans.begin(), ans.end(), a[i][0]) - ans.begin();
				int r = upper_bound(ans.begin(), ans.end(), a[i][1]) - ans.begin();
				if (r - l != a[i][1] - a[i][0] + 1) res[a[i][2]] = '1';
			}
		}

        cout << res << el;
    }

    return 0;
}

