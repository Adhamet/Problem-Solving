#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	 int t; cin >> t;
	 while (t--) {
		 string s;
		 cin >> s;

		 int x = stoi(s);
		 if ((float)sqrt(x) != (int)sqrt(x)) cout << -1 << el;
		 else {
			 int sqx = sqrt(x);
			 cout << sqx-1 << ' ' << 1 << el;
		 }
	 }

	return 0;
}
