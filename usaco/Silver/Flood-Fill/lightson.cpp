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
constexpr int MAXN = 105;
int n, m, cnt = 1;
bool lit[MAXN][MAXN], vis[MAXN][MAXN];
vector<pair<int, int>> canTurnOn[MAXN][MAXN];

bool connected(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (vis[nx][ny]) return true;
	}
	return false;
}

void floodfill(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n || !lit[x][y] || vis[x][y]) return;
	if (!connected(x, y) && !(x == 0 && y == 0)) return;

	vis[x][y] = true;
	for (auto [nx, ny]: canTurnOn[x][y]) {
		if (!lit[nx][ny]) cnt += 1;
		lit[nx][ny] = true;
	}

	for (int i = 0; i < 4; i++) floodfill(x + dx[i], y + dy[i]);
	for (int i = 0; i < canTurnOn[x][y].size(); i++) {
		int nx = canTurnOn[x][y][i].first;
		int ny = canTurnOn[x][y][i].second;

		if (!lit[nx][ny]) cnt += 1;
		lit[nx][ny] = true;
		floodfill(nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("lightson");
	cin >> n >> m;

	int x, y, a, b;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> a >> b;
		canTurnOn[x - 1][y - 1].push_back({a - 1, b - 1});
	}

	lit[0][0] = true;
	floodfill(0, 0);
	cout << cnt << el;
	return 0;
}
