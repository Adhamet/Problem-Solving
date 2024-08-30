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

	ll n;
	cin >> n;

	vector<pi> a(n);
	for (auto &i: a) cin >> i.F >> i.S;
	sort(a.begin(), a.end());
	
	ll sum = 0, time = 0;
	for (int i = 0; i < n; i++) {
		time += a[i].F;
		sum += (a[i].S - time);
	}
	cout << sum << el;
	
	return 0;
}
