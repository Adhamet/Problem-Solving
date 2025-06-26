#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<i64> a(4);
	for (int i = 0; i < 4; ++i) cin >> a[i];
	bool acc = false;
	if (a[0]+a[1]==a[2]+a[3]) acc = true;
	if (a[0]+a[2]==a[1]+a[3]) acc = true;
	if (a[0]+a[3]==a[1]+a[2]) acc = true;
	return cout << (acc? "YES": "NO"), 0;
}
