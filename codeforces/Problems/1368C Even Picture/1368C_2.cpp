#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	vector<array<int, 2>> ans;
	ans.push_back({0, 0});
	for (int i = 0; i <= n; ++i) {
		ans.push_back({i, i + 1});
		ans.push_back({i + 1, i});
		ans.push_back({i + 1, i + 1});
	}

	printf("%d\n", (int32_t)ans.size());
	for (auto &a: ans) printf("%d %d\n", a[0], a[1]);
	return 0;
}
