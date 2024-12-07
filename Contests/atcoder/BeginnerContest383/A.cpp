#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<array<int, 2>> time(n);
	for (int i = 0; i < n; i++) cin >> time[i][0] >> time[i][1];
	int currLiters = time[0][1];
	for (int i = 1; i < n; i++) {
		int diff = (time[i][0] - time[i - 1][0]);
		currLiters = max(0LL, currLiters - diff);
		currLiters += time[i][1];
	}

	cout << currLiters;
	return 0;
}
