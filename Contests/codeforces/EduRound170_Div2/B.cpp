#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'
#define MOD 1000000007

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    vector<int> n(t), k(t);
    for (int i = 0; i < t; i++) cin >> n[i];
    for (int i = 0; i < t; i++) cin >> k[i];

	for (int i = 0; i < t; i++) {
		int ans = 1, base = 2;

		while (k[i] > 0) {
			if (k[i] % 2 == 1) ans = (1LL * base * ans) % MOD;
			base = (1LL * base * base) % MOD;
			k[i] /= 2;
		}

		cout << ans << endl;
	}
    return 0;
}

