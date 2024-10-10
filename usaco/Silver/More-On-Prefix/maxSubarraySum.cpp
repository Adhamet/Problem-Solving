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
	ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
 
	int n;
	cin >> n;
 
	vector<ll> pref(n + 1);
	
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
 
		pref[i + 1] = pref[i] + x;
	}
 
	ll max_subarr_sum = pref[1];
	ll currMin = pref[0];
	for (int i = 1; i <= n; i++) {
		max_subarr_sum = max(max_subarr_sum, pref[i] - currMin);
		currMin = min(currMin, pref[i]);
	}
	cout << max_subarr_sum;
	
	return 0;
}
