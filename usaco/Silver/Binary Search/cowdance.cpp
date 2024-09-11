#include <bits/stdc++.h>
#include <complex>
#include <queue>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int firstTrue(int l, int r, function<bool(int)> can) {
	int ans = 0;

	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (can(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	setIO("cowdance");

	ll n, tmax;
	cin >> n >> tmax;

	vector<int> dura(n);
	for (auto &i: dura) cin >> i;

	int minK = firstTrue(1, n, [&](int mid) { 
		int lastTime = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < n; i++) {
            if (pq.size() == mid) lastTime = pq.top(), pq.pop();
			if (lastTime + dura[i] > tmax) return false;
			pq.push(lastTime + dura[i]);
		}

		return true;
	});

	cout << minK << el;

	return 0;
}
