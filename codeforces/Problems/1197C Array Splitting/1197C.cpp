#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> gaps(n - 1);
	for (int i = 0; i < n - 1; i++) gaps[i] = a[i + 1] - a[i];
	sort(gaps.rbegin(), gaps.rend());
	int cost = a[n - 1] - a[0];
	for (int i = 0; i < k - 1; i++) cost -= gaps[i];
	return cout << cost, 0;
}
