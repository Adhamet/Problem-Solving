#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n = 100;
	i64 fs = n * (n + 1) / 2;
	fs = fs * fs;
	i64 sc = n * (n + 1) * (2 * n + 1) / 6;
	return cout << fs - sc, 0;
}
