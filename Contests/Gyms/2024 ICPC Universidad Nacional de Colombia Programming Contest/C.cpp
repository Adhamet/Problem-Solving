#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'
#define int i64

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<int> upsPre(n, 0), upsSuff(n, 0);
	for (int i = 0; i < n - 1; ++i) upsPre[i + 1] = upsPre[i] + (a[i + 1] > a[i]);
	for (int i = n - 1; i > 0; --i) upsSuff[i - 1] = upsSuff[i] + (a[i - 1] > a[i]);

	vector<int> eq(n);
	for (int i = 0; i < n; ++i) eq[i] = upsPre[i] + upsSuff[i];

	unordered_map<int, int> freq;
	for (int i = 0; i < n; ++i) freq[eq[i]] += 1;
	i64 ans = 0;
	for (auto &[val, cnt]: freq) ans += (cnt * (cnt + 1) / 2);
	return cout << ans, 0;
}
