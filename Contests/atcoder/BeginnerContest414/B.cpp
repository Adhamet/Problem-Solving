#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	string s = "";
	int cur = 0;

	bool deny = false;
	for (int i = 0; i < n; ++i) {
		char c;
		int l;
		cin >> c >> l;

		if (cur + l > 100) deny = true;
		if (!deny) {
			cur += l;
			for (int i = 0; i < l; ++i) s += c;
		}
	}

	return cout << (deny? "Too Long": s), 0;
}
