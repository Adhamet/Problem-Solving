#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

const int MXN = 1e3 + 5, M = 1e9 + 7;

i64 mem[MXN+1][MXN+1];

i64 go(int n, int k) {
	if (k < 0 || k >= n) return 0;
	if (n == 1 && k == 0) return 1;

	i64 &ret = mem[n][k];
	if (~ret) return ret;
	ret = 0;

	ret = (ret + (((n - k) * go(n - 1, k - 1)) % M)) % M;
	ret = (ret + (((k + 1) * go(n - 1, k)) % M)) % M;
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	memset(mem, -1, sizeof mem);
	int t;	cin >> t;
	while (t--) {
		int n, k;	cin >> n >> k;
		cout << go(n, k) << el;
	}

	return 0;
}
