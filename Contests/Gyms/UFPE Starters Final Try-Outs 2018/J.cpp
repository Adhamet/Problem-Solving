#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i64 n, k, mxA = 0;	cin >> n >> k;
	vector<i64> a(n), b(n), c(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		mxA = max(mxA, a[i]);
	}

	auto can = [&](i64 x) {
		i64 exc = 0, reqS = 0;
		for (int i = 0; i < n; ++i) if (a[i] > x) {
			i64 curr = a[i] - x;
			exc += curr;
			reqS += curr * b[i];
			if (reqS > k) return false;
		}

		if (exc == 0) return true;

		priority_queue<pair<i64,i64>, vector<pair<i64,i64>>, greater<>> pq;
		for (int j = 0; j < n; ++j) if (a[j] < x) {
			pq.push({c[j], x - a[j]});
		}

		i64 reqD = 0;
		while (!pq.empty() && exc > 0) {
			auto [cj, cap] = pq.top();
			pq.pop();

			i64 tk = min(cap, exc);
			reqD += tk * cj;
			if (reqS + reqD > k) return false;
			exc -= tk;
		}

		if (exc > 0) return false;
		return (exc > 0? false: reqS+reqD<=k);
	};

	i64 l = 0, r = mxA, ans = mxA;
	while (l <= r) {
		i64 md = (l + r) >> 1;
		if (can(md)) r = md - 1, ans = md;
		else l = md + 1;
	}

	return cout << ans, 0;
}
