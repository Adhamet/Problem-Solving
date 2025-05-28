#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int a,b,c,d; cin >> a >> b >> c >> d;
		int op1 = (a+b), op2 = (c-b), op3 = (d-c);
		if (op1 == op2) {
			if (op2 == op3) cout << 3 << el;
			else cout << 2 << el;
		} else if (op1 == op3) cout << 2 << el;
		else if (op2 == op3) cout << 2 << el;
		else cout << 1 << el;
	}

	return 0;
}
