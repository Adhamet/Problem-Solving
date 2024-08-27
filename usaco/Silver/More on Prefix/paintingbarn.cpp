#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 1e3 + 2;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);
 
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> barn(N, vector<int>(N));
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		barn[x1][y1] += 1;
		barn[x1][y2] -= 1;
		barn[x2][y2] += 1;
		barn[x2][y1] -= 1;
	}

	int area = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i > 0) barn[i][j] += barn[i - 1][j];
			if (j > 0) barn[i][j] += barn[i][j - 1];
			if (i > 0 && j > 0) barn[i][j] -= barn[i - 1][j - 1];
			area += (barn[i][j] == k);
		}
	}
	cout << area << el;

	return 0;
}
