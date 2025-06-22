#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	string s, t;
	cin >> s >> t;

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'o' && t[i] == 'o') return cout << "Yes", 0;
	}

	return cout << "No", 0;
}
