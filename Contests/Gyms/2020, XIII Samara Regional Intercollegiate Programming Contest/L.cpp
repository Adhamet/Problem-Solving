#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;	cin >> n;
	vector<i64> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	i64 sum = 0, k = 0;
	priority_queue<i64, vector<i64>, greater<>> pq;
	for (int i = 0; i < n; ++i) {
		k++;
		sum += a[i];
		pq.push(a[i]);

		while (!pq.empty() && pq.top() < k) {
			sum -= pq.top();
			k--;
			pq.pop();
		}
	}

	i64 ans = sum - k*(k+1)/2;
	return cout << ans, 0;
}
