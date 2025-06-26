#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<int> ans;
	ans.push_back(1);
	for (int i = 1; i < n; i+=2) {
		if (i + 2 <= n) ans.push_back(i+2);
		else ans.push_back(n);
	} 

	cout << (int)ans.size() << el;
	for (auto&x: ans) cout << x << ' ';
	return 0;
}
