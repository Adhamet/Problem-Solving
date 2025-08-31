#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int ones = 0, zeros = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') ones += 1;
		else zeros += 1;
	}

	int left = 0;
	for (int i = 0; i < ones; ++i) left += (1 << i);
	int right = 0;
	for (int i = 0; i < zeros; ++i) right += (1 << i);

	int end = (1 << n);
	for (int x = 1; x <= end; ++x) {
		if (x > left && end - x >= right) {
			cout << x << ' ';
		}
	}

	return 0;
}
