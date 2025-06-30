#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int r, c;	cin >> r >> c;
	if (r == 1 && c == 1) return cout << 0, 0;
	
	vector<i64> rv(r), cv(c);
	if (r >= 2 && c >= 2) {
		for (int i = 0; i < r; ++i) rv[i] = i + 1;
		for (int j = 0; j < c; ++j) cv[j] = r + j + 1;
	} else if (r == 1) {
		rv[0] = 1;
		for (int j = 0; j < c; ++j) cv[j] = j + 2;
	} else {
		cv[0] = 1;
		for (int i = 0; i < r; ++i) rv[i] = i + 2;
	}
	
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cout << rv[i] * cv[j] << (j+1 < c? ' ': el);
	return 0;
}
