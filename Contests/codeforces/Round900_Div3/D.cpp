#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 2e5;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;
		s = ' ' + s;
		
		vector<int> l(N), r(N);
		for (int i = 1; i <= k; i++) cin >> l[i];
		for (int i = 1; i <= k; i++) cin >> r[i];

		int q;
		cin >> q;

		vector<int> update(N);
		for (int i = 1; i <= q; i++) {
			int x;
			cin >> x;

			int lf = 1, rt = k, key = lf;
			while (lf < rt) {
				int mid = (lf + rt) / 2;
				if (r[mid] < x) lf = mid + 1, key = mid + 1;
				else rt = mid;
			}

			int a = min(x, r[key] + l[key] - x);
			int b = max(x, r[key] + l[key] - x);

			if (l[key] == r[key]) continue;
			update[a] += 1;
			update[b + 1] -= 1;
		}

		for (int i = 1; i <= n; i++) update[i] += update[i - 1];

		for (int i = 1; i <= k; i++) {
			int rt = r[i];
			for (int lf = l[i]; lf <= (r[i]+l[i])/2; lf++) {
				if (update[lf] % 2 == 1) swap(s[lf], s[rt]);
				rt -= 1;
			}
		}

		for (int i = 1; i <= n; i++) cout << s[i];
		cout << el;
	}
	
	return 0;
}
