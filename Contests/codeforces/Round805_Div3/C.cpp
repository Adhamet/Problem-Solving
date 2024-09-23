#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	
	while (t--) { 
		int n, q;
		cin >> n >> q;

		vector<int> a(n);
		map<int, array<int, 2>> mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (mp.find(a[i]) == mp.end()) mp[a[i]] = {i, i};
			else mp[a[i]][1] = i;
		}

		while (q--) {
			int l, r;
			cin >> l >> r;

			if (mp.find(l) != mp.end() && mp.find(r) != mp.end() && mp[l][0] <= mp[r][1]) {
				cout << "YES" << el;
			} else cout << "NO" << el;
		}
	}
	
	return 0;
}
