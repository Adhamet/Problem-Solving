#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

struct event {
	int type, time, position, n;
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<event> a(n);
	for (auto &e: a) cin >> e.type >> e.time >> e.position >> e.n;

	sort(begin(a), end(a), [&](event &e1, event &e2) {
		if ((e1.position - e1.time) == (e2.position - e2.time)) return e1.time > e2.time;
		return (e1.position - e1.time) < (e2.position - e2.time);
	});
	reverse(a.begin(), a.end());

	map<int, int, greater<int>> mp;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].type == 1) {
			mp[a[i].position + a[i].time] += a[i].n;
		} else {
			int curr = a[i].n;
			auto itr = mp.lower_bound(a[i].position + a[i].time);
			while (itr != mp.end() && curr > 0) {
				if (curr >= itr->second) {
					curr -= itr->second;
					ans += itr->second;
					itr->second = 0;
					itr = mp.erase(itr);
				} else {
					itr->second -= curr;
					ans += curr;
					curr = 0;
					itr++;
				}
			}
		}
	}
	cout << ans;

	return 0;
}
