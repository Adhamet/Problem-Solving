#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main()	{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n), b(n);
		map<int, queue<int>> mp;
		for (auto &i: a) cin >> i;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			if (b[i] != a[i]) {
				mp[b[i]].push(i);
			}
		} 

		int m;
		cin >> m;

		vector<int> d(m);
		for (auto &i: d) cin >> i;

		int last = -1;
		for (int i = 0; i < n; i++) {
			if (b[i] == d.back()) {
				last = i;
			}
		}

		if (last == -1) {
			cout << "NO\n";
			continue;
		} else {
			for (int i: d) {
				if (mp[i].empty()) continue;
				
				a[mp[i].front()] = i;
				mp[i].pop();
			}

			bool match = true;
			
			for (int i = 0; i < n; i++) {
				if (a[i] != b[i]) {
					match = false;
					break;
				}
			}

			cout << (match ? "YES\n" : "NO\n");
		}
	}

	return 0;
}
