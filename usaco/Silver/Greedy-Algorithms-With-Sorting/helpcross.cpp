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

	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);
	
	int c, n;
	cin >> c >> n;

	pair<int, int> cows[n];
	multiset<ll> ms;
	for (int i = 0; i < c; i++) {
		int num;
		cin >> num;
		ms.insert(num);
	}

	for (auto &i: cows) cin >> i.S >> i.F;
	sort(cows, cows + n);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto itr = ms.lower_bound(cows[i].S);
		
		if (itr == ms.end()) continue;
		else if (*itr <= cows[i].F) ans += 1, ms.erase(itr);
	}
	cout << ans;
	
	return 0;
}
