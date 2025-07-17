#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define int i64
#define el '\n'

constexpr int MXN = 3e5+5;

int n, a[MXN], b[MXN], mem[MXN][4];
int missA, missB;

int go(int idx, int msk) {
	if (idx == n) return (msk == 3? 0: -1);

	int &ret = mem[idx][msk];
	if (~ret) return ret;
	ret = 0;

	for (int nmsk = msk; nmsk < 4; nmsk = (nmsk + 1) | msk) {
		int curra;
		if ((nmsk & 1) && !(msk & 1)) curra = missA;
		else {
			if (msk & 1) curra = a[idx-1];
			else curra = a[idx];
		}

		int currb;
		if ((nmsk & 2) && !(msk & 2)) currb = missB;
		else {
			if (msk & 2) currb = b[idx-1];
			else currb = b[idx];
		}

		int nxt = go(idx+1, nmsk);
		if (nxt != -1) ret = max(ret, abs(curra - currb) + nxt);
		if (nmsk == 3) break;
	}

	return ret;
}

vector<int> aa, bb;
void build(int idx, int msk) {
	if (idx == n) return;

	for (int nmsk = msk; nmsk < 4; nmsk = (nmsk + 1) | msk) {
		int curra;
		if ((nmsk & 1) && !(msk & 1)) curra = missA;
		else {
			if (msk & 1) curra = a[idx-1];
			else curra = a[idx];
		}

		int currb;
		if ((nmsk & 2) && !(msk & 2)) currb = missB;
		else {
			if (msk & 2) currb = b[idx-1];
			else currb = b[idx];
		}

		int nxt = go(idx+1, nmsk);
		if (nxt != -1 && abs(curra - currb) + nxt == mem[idx][msk]) {
			aa.push_back(curra);
			bb.push_back(currb);
			build(idx + 1, nmsk);
			return;
		}

		if (nmsk == 3) break;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	vector<bool> seenA(n+1, false), seenB(n+1, false);
	for (int i = 0; i < n - 1; ++i) {
		cin >> a[i];
		seenA[a[i]] = true;
	}

	for (int i = 0; i < n - 1; ++i) {
		cin >> b[i];
		seenB[b[i]] = true;
	}

	for (int x = 1; x <= n; ++x) {
		if (!seenA[x]) missA = x;
		if (!seenB[x]) missB = x;
	}

	memset(mem, -1, sizeof mem);
	cout << go(0, 0) << el;

	build(0, 0);
	for (auto &x: aa) cout << x << ' ';
	cout << el;
	for (auto &x: bb) cout << x << ' ';
	return cout << el, 0;
}
