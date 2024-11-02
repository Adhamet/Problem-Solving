#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> grid(n);
		for (auto &row: grid) cin >> row;
		int cnt = 0;
		for (int layer = 0; layer < min(n, m) / 2; layer++) {
			int lowR = layer, lowC = layer;
			int highR = n - layer - 1, highC = m - layer - 1;
			string str = grid[lowR].substr(lowC, highC - lowC + 1);
			for (int r = lowR + 1; r < highR; r++) str += grid[r][highC];
			for (int c = highC; c >= lowC; c--) str += grid[highR][c];
			for (int r = highR - 1; r > lowR; r--) str += grid[r][lowC];
			str += str.substr(0, 3);
			for (int i = 0; i + 4 <= int(str.size()); i++) cnt += (str.substr(i, 4) == "1543");
		}
		cout << cnt << el;
	}

	return 0;
}	
