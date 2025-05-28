#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		set<int> st;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			st.insert(x);
		}

		cout << (int)st.size() << el;
	}

	return 0;
}
