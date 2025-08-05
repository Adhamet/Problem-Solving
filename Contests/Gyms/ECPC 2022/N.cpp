#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		bool acc = true;
		stack<int> stk;
		unordered_set<int> inStk, ban;
		for (int i = 0; i < n; ++i) {
			if (ban.count(a[i])) {
				acc = false;
				break;
			}

			if (inStk.count(a[i])) {
				while (stk.top() != a[i]) {
					ban.insert(stk.top()); 
					inStk.erase(stk.top());
					stk.pop();
				}
			} else {
				stk.push(a[i]);
				inStk.insert(a[i]);
			}
		}

		cout << (acc? "YES": "NO") << el;
	}

	return 0;
}
