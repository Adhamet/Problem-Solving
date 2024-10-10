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

	ll n, x;
	cin >> n >> x;

	deque<ll> dq(n);
	for (auto &i: dq) cin >> i;
	sort(dq.begin(), dq.end());

	int cnt = 0;
	while (!dq.empty()) {
		if (dq.size() >= 2) {
			if (dq.front() + dq.back() > x) {
				cnt += 1;
				dq.pop_back();
			} else {
				cnt += 1;
				dq.pop_front();
				dq.pop_back();
			}
		} else if (x >= dq.front()) {
			cnt += 1;
			dq.pop_front();
		}
	}
	cout << cnt << el;

	return 0;
}
