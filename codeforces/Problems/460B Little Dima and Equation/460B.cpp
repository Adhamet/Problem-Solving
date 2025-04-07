#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

i64 calc(i64 k) {
	string strk = to_string(k);
	i64 sum = 0;
	for (int i = 0; i < (i32)strk.size(); ++i) sum += (strk[i] - '0');
	return sum;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i64 a, b, c;
	vector<i64> ans;
	cin >> a >> b >> c;

	for (i64 i = 1; i <= 81; ++i) {
		i64 _pow = 1;
		for (i64 j = 1; j <= a; ++j) _pow *= i;

		i64 fx = b * _pow + c;
		if (fx <= 0 || fx >= 1e9) continue;
		if (calc(fx) == i) ans.push_back(fx);
	}

	i32 sz = (i32)ans.size();
	printf("%d\n", sz);
	for (int i = 0; i < sz; ++i) printf("%lld ", ans[i]);
	return 0;
}

