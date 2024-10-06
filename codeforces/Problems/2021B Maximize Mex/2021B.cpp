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
		ll n, x;
		cin >> n >> x;

		map<ll, ll> cnt;
		vector<ll> a(n);
		for (auto &i: a) cin >> i, cnt[i] += 1;
		for (int i = 0; i <= n + 1; i++) {
			if (cnt[i] == 0) {
				cout << i << el;
				break;
			} else if (cnt[i] > 1) cnt[i+x] += (cnt[i]-1), cnt[i] = 1;
		}
	}

	return 0;
}
