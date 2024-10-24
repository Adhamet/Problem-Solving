#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fst first
#define scd second
#define el '\n'
#define MOD 1000000007

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int MAXN = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &i: a) cin >> i;

		map<ll, int> pref;
		ll sum = 0, cnt = 0, last = -1;
		pref[0] = -1;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (pref.count(sum) && pref[sum] >= last) cnt += 1, last = i;
			pref[sum] = i;
		}

		cout << cnt << el;
	}

	return 0;
}
