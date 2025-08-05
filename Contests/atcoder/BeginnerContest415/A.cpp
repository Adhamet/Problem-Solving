#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int x;	cin >> x;
	bool acc = false;
	for (int i = 0; i < n; ++i) if (a[i] == x)
		acc = true;
	return cout << (acc? "Yes": "No"), 0;
}
