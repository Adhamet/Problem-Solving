#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 1005;
/*const int oo = 1e9 + 20;*/
int n, m;
bool vis[N][N];
char adjMtrx[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y) {
	if (!valid(x, y) || vis[x][y] || adjMtrx[x][y] == '#') return;		
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	memset(vis, 0, sizeof vis);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adjMtrx[i][j];
		}
	}

	int rooms = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || adjMtrx[i][j] == '#') continue;

			dfs(i, j);
			rooms += 1;
		}
	}

	cout << rooms << el;
	return 0;
}
