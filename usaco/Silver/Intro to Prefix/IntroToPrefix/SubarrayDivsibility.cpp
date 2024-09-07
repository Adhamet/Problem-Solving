// cses
#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<int> MOD(n, -1);
	MOD[0] = 0;

	ll ans = 0, pref = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		pref = (pref + x) % n;	// mod calculations
		pref = (pref + n) % n;	// extra-step for negative values

		MOD[pref]++;
		ans += MOD[pref];
	}
	cout << ans << el;

	return 0;
}
