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
		int n;
		cin >> n;

		vector<ll> a(n);
		for (auto &i: a) cin >> i;
		sort(a.begin(), a.end());

		map<ll, int> mp;
		for (int i = (n - 1) / 2; i < n; i++) mp[a[i]] += 1;
		cout << mp[a[(n - 1) / 2]] << el;
	}

	return 0;
}

