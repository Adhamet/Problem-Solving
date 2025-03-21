#include <bits/stdc++.h>
using namespace std;
#define el '\n'

string s;
int32_t solve(int32_t l, int32_t r, char c) {
	if (l == r) return s[l] == c ? 0: 1;
	int32_t mid = (l + r) >> 1;
	int32_t left = 0, right = 0;
	for (int32_t i = l; i <= mid; ++i) left += (s[i] != c);
	for (int32_t i = mid + 1; i <= r; ++i) right += (s[i] != c);
	return min((left + solve(mid + 1, r, c + 1)), (right + solve(l, mid, c + 1)));
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int32_t tc;
	cin >> tc;
	while (tc--) {
		int32_t n;
		cin >> n >> s;
		cout << solve(0, n - 1, 'a') << el;
	}

	return 0;
}
