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
 
	vector<pi> a(n);
	for (auto &i: a) cin >> i.F >> i.S;
	sort(a.begin(), a.end(), [](pi a, pi b) { return a.S < b.S; });
 
	int cnt = 0, curr = 0;
	for (int i = 0; i < n; i++) if (a[i].F >= curr) {
		cnt += 1, curr = a[i].S;
	}
	cout << cnt << el;
 
	return 0;
}
