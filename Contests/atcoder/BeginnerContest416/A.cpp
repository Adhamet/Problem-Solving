#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, l, r;
	cin >> n >> l >> r;
	string s;	cin >> s;
	for (int i = l-1; i <= r-1; ++i) if (s[i] == 'x')
		return cout << "No", 0;
	return cout << "Yes", 0;
}
