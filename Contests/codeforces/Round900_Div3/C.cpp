#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 2e6;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll t;
	cin >> t;

	while (t--) {
		ll n, k, x;
		cin >> n >> k >> x;

		bool op1 = (x < k*(k+1)/2);
		bool op2 = (x > k*(n+n-k+1)/2);

		if (op1 || op2) cout << "NO" << el;
		else cout << "YES" << el;
	}
	
	return 0;
}
