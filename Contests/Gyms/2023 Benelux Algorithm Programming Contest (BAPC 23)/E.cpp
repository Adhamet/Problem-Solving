#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 2005;
int n, a[MXN][4];
int mem[MXN][MXN];

int go(int i, int j, int start, int prep) {
	if (i == n) return 0;

	int &ret = mem[i][j];
	if (~ret) return ret;
	ret = 0;

	int prepared = j - start;
	int curr = i - start;
	if (curr >= 0 && curr < prepared) {
		int tm = a[i][1] - a[i][0];
		
		ret = max(ret, 1 + go(i + 1, j + 1, start, ));
	} else ret = max(ret, go(i + 1, j, start, ));
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 4; ++i)
			cin >> a[i][j];

	memset(mem, -1, sizeof mem);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, go(0, i, i, ));
	return cout << ans, 0;
}
