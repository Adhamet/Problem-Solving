#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	auto f = [](int x) { return x * (x + 1) / 2; };
	cout << (3 * f(999/3)) + (5 * f(999/5)) - (15 * f(999/15));

	return 0;
}
