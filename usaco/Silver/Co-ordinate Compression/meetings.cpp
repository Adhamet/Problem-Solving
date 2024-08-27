#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

struct cow {
	int w, x, d;
};

bool comparator(cow a, cow b) {
	return a.x < b.x;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("meetings.in", "r", stdin);
	freopen("meetings.out", "w", stdout);
	
	int n, lb;
	cin >> n >> lb;

	ll totalW = 0;
	vector<cow> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i].w >> cows[i].x >> cows[i].d;
		totalW += cows[i].w;
	}

	sort(cows.begin(), cows.end(), comparator);
	
	vector<cow> l, r;
	for (auto c: cows) {
		if (c.d == -1) l.push_back(c);
		else r.push_back(c);
	}

	vector<pi> times;
	for (int i = 0; i < l.size(); i++) times.push_back({l[i].x, cows[i].w});
	for (int i = 0; i < r.size(); i++) times.push_back({lb - r[i].x, cows[l.size() + i].w});

	sort(times.begin(), times.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.first < b.first;
	});

	int T = -1;
	for (auto [time, weight]: times) {
		totalW -= 2 * weight;
		if (totalW <= 0) {
			T = time;
			break;
		}
	}

	int meets = 0;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (cows[i].d == 1) q.push(cows[i].x);
		else {
			while (!q.empty() && (q.front() + 2 * T) < cows[i].x) q.pop();
			meets += q.size();
		}
	}
	cout << meets << el;
	
	return 0;
}
