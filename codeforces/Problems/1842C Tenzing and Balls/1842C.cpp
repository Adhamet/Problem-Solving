#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

const int MXN = 2e5 + 5;

int n, a[MXN], mem[MXN][2];
int nxt[MXN];

int go(int idx, bool rem) {
	if (idx == n) return 0;

	int &ret = mem[idx][rem];
	if (~ret) return ret;

	ret = go(idx + 1, 0);
	if (nxt[idx] != -1) ret = max(ret, (nxt[idx] - idx) + go(nxt[idx], 1));
	if (rem) ret = max(ret, 1 + go(idx + 1, 0));
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> last;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			nxt[i] = -1;
		}

		for (int i = n-1; i >= 0; --i) {
			if (last.count(a[i])) nxt[i] = last[a[i]];
			last[a[i]] = i;
		}

		for (int i = 0; i <= n; ++i) mem[i][0] = mem[i][1] = -1;
		cout << go(0, 0) << '\n';
	}

	return 0;
}


