#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<i64> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	vector<i64> futureMx(n + 1, 0);
	for (int i = n - 1; i >= 0; i--)
		futureMx[i] = max({a[i], b[i], futureMx[i + 1]});
	i64 profit = 0;
	for (int i = 0; i < n; i++) {
		i64 mnP = min(a[i], b[i]);
		i64 sameDay = (b[i] > a[i]) ? (b[i] - a[i]): 0;
		i64 futureProfit = futureMx[i + 1] - mnP;
		profit += max(sameDay, futureProfit);
	}

	return cout << profit, 0;
}

