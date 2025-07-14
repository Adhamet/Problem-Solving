#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 1005;

int n, d, mem[MXN][(1<<10)];
vector<vector<int>> nums;

int go(int idx, int msk) {
	if (msk == (1<<10) - 1) return 0;
	if (idx == n) return 1e9;

	int &ret = mem[idx][msk];
	if (~ret) return ret;
	ret = 1e9;

	int nmsk = msk;
	for (int i = 0; i < d; ++i)
		nmsk = nmsk | (1ll << nums[idx][i]);
	
	ret = min(ret, go(idx + 1, msk));
	return ret = min(ret, 1 + go(idx + 1, nmsk));
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;		cin >> t;
	while (t--) {
		memset(mem, -1, sizeof mem);
		cin >> n >> d;
		nums.assign(n, vector<int>(d));
		
		for (int i = 0; i < n; ++i) {
			string s;	cin >> s;
			for (int j = 0; j < d; ++j) nums[i][j] = (s[j] - '0');
		}

		int ans = go(0, 0);
		cout << (ans != 1e9? ans: -1) << el;
	}
	
	return 0;
}
