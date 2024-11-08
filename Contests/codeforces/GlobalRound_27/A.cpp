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
		ll n, m, r, c;
		cin >> n >> m >> r >> c;

		ll ans = (m - c);
		for (int i = r + 1; i <= n; i++) {
			ans += (m - 1) + 1;
			ans += (m - 1);
		}
		
		cout << ans << el;
	}

	return 0;
}
