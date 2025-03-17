#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int32_t n;
	string s, t;
	cin >> n >> s >> t;
	int32_t i = 0, j = 0, k = 0, ans = 0;
	for (i = 0; s[i] == t[i]; ++i);
	for (j = n - 1; s[j] == t[j]; --j);
	for (k = i; k < j && s[k] == t[k+1]; k++);
	if (k == j) ans += 1;
	for (k = i; k < j && s[k+1] == t[k]; k++);
	if (k == j) ans += 1;
	return cout << ans, 0;
}

