#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

const int N = 1005;
/*const int oo = 1e9 + 20;*/
int n, currA, currP;
bool vis[N][N];
char grid[N][N];

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == '.') {
		currP += 1;
		return;
	}

	if (vis[x][y]) return;
	else vis[x][y] = true;

	if (grid[x][y] == '#') currA += 1;
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x - 1, y);
	dfs(x + 1, y);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("perimeter");

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int area = INT_MIN, peri = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j] && grid[i][j] == '#') {
				dfs(i, j);

				if (area == currA) peri = min(peri, currP);
				else area = max(area, currA), peri = max(peri, currP);

				currA = currP = 0;
			}
		}
	}

	cout << area << " " << peri << el;
	return 0;
}
