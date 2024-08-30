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

	int n, k;
	cin >> n >> k;

	vector<pi> a(n);
	multiset<int> tops;
	for (auto &i: a) cin >> i.F >> i.S;
	sort(a.begin(), a.end(), [](pi a, pi b) { return a.S < b.S; });

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		auto itr = tops.upper_bound(a[i].F);
		if (itr != tops.begin()) tops.erase(--itr);
		if (tops.size() < k) tops.insert(a[i].S), cnt += 1;
	}
	cout << cnt;
	
	return 0;
}
