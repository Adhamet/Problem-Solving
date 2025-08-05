#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, a, b;
	string s;	cin >> n >> a >> b >> s;
	while (b) s.pop_back(), b--;
	return cout << s.substr(a), 0;
}
