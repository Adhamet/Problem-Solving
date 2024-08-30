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

	vector<ll> a(n);
	for (auto &i: a) cin >> i;
	sort(a.begin(), a.end());

	ll x = 0, num = a[n / 2];
	for (int i = 0; i < n; i++) x += abs(a[i] - num);
	cout << x << el;

	return 0;
}
