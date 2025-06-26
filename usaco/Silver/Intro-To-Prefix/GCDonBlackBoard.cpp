#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 2e5+10;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);

	int n, ans = 0;
	cin >> n;

	vector<int> vec(n), pref(n + 1, 0), suff(n + 2, 0);
	pref[0] = 0;
	suff[n + 1] = 0;

	for (int i = 0; i < n; i++) cin >> vec[i];

	for (int i = 1; i <= n; i++) pref[i] = __gcd(pref[i - 1], vec[i - 1]);
	for (int i = n; i >= 1; i--) suff[i] = __gcd(suff[i + 1], vec[i - 1]);

	for (int i = 1; i <= n; i++) {
		ans = max(ans, __gcd(pref[i - 1], suff[i + 1]));
	}

	cout << ans << el;
	
	return 0;
}

