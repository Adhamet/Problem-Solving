#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define fst first
#define scd second
#define el '\n'

constexpr int MXN = 1e5+3;

int n, p, k;
i64 mem[MXN][(1<<7)];
vector<pair<i64, int>> aud;
vector<vector<i64>> str;

i64 go(int idx, int msk, int k) {
	if (idx == n) return 0;

	i64 &ret = mem[idx][msk];
	if (~ret) return ret;
	ret = 0;

	if (k) ret = max(ret, aud[idx].fst + go(idx + 1, msk, k - 1));
	else ret = max(ret, go(idx + 1, msk, k));
	if (__builtin_popcount(msk) < p) {
		for (int i = 0; i < p; ++i) if ((msk & (1ll<<i)) == 0) {
			int nmsk = msk | (1ll << i);
			ret = max(ret, str[aud[idx].scd][i] + go(idx + 1, nmsk, k));
		}
	}

	return ret;
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	memset(mem, -1, sizeof mem);
	cin >> n >> p >> k;
	aud = vector<pair<i64, int>>(n);
	str = vector<vector<i64>>(n, vector<i64>(p));
	for (int i = 0; i < n; ++i) cin >> aud[i].fst, aud[i].scd = i;
	sort(aud.rbegin(), aud.rend());
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < p; ++j)
			cin >> str[i][j];
	cout << go(0, 0, k) << el;
	
	return 0;
}#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define fst first
#define scd second
#define el '\n'

constexpr int MXN = 1e5+3;

int n, p, k;
i64 mem[MXN][(1<<7)];
vector<pair<i64, int>> aud;
vector<vector<i64>> str;

i64 go(int idx, int msk, int k) {
	if (idx == n) return 0;

	i64 &ret = mem[idx][msk];
	if (~ret) return ret;
	ret = 0;

	if (k) ret = max(ret, aud[idx].fst + go(idx + 1, msk, k - 1));
	else ret = max(ret, go(idx + 1, msk, k));
	if (__builtin_popcount(msk) < p) {
		for (int i = 0; i < p; ++i) if ((msk & (1ll<<i)) == 0) {
			int nmsk = msk | (1ll << i);
			ret = max(ret, str[aud[idx].scd][i] + go(idx + 1, nmsk, k));
		}
	}

	return ret;
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	memset(mem, -1, sizeof mem);
	cin >> n >> p >> k;
	aud = vector<pair<i64, int>>(n);
	str = vector<vector<i64>>(n, vector<i64>(p));
	for (int i = 0; i < n; ++i) cin >> aud[i].fst, aud[i].scd = i;
	sort(aud.rbegin(), aud.rend());
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < p; ++j)
			cin >> str[i][j];
	cout << go(0, 0, k) << el;
	
	return 0;
}
