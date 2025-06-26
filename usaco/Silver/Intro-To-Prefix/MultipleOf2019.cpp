#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 2019;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);

	string s;
	cin >> s;
	int n = s.length();

	vector<int> vec(MOD);
	vec[0] = 1;
	
	ll ans = 0, suff = 0, pot = 1;
	for (int i = n - 1; i >= 0; i--) {
		ll digit = (s[i] - '0');
		suff = (suff + (digit * pot)) % MOD;
		pot = (pot * 10) % MOD;

		ans += vec[suff]++;
	}
	cout << ans << el;
	
	return 0;
}

