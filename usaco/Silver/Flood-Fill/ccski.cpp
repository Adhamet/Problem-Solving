#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/
void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
constexpr int MAXN = 500;
int n, m, wx, wy;
int grid[MAXN][MAXN];
int wp[MAXN][MAXN];
bool vis[MAXN][MAXN];

void floodfill(int diff) {
	queue<pair<int, int>> q;
	q.push(make_pair(wx, wy));
	vis[wx][wy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
				if (abs(grid[x][y] - grid[nx][ny]) <= diff) {
					vis[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
	}
}

bool reachable(int mid) {
	memset(vis, false, sizeof vis);
	floodfill(mid);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (wp[i][j] && !vis[i][j]) return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("ccski");
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		} 
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int waypoint;
			cin >> waypoint;
			wp[i][j] = (waypoint != 0);
			if (wp[i][j]) wx = i, wy = j;
		}
	}

	int l = 0, r = INT32_MAX;
	while (l < r) {
		int mid = (l + r) / 2;
		if (reachable(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << el;
	return 0;
}
