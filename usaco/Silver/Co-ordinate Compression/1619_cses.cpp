#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
 
using ll = long long;
using pi = pair<int, int>;
 
// const ll N = 2e5+20;
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);
 
	ll n;
	cin >> n;
 
	vector<array<ll, 2>> arr;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
 
		arr.push_back({a, 1LL}), arr.push_back({b, -1LL});
	}
 
	sort(arr.begin(), arr.end());
	
	int mx = 0, curr = 0;
	for (auto &i: arr) {
		curr += i[1];
		mx = max(mx, curr);
	}
	cout << mx << el;
	
	return 0;
