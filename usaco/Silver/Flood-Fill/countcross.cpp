#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fst first
#define scd second
#define el '\n'
#define MOD 1000000007

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

const int MAXN = 105;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
bool vis[MAXN][MAXN], road[MAXN][MAXN][4];
int N, K, R;
vector<pi> cows;

bool valid(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

int floodfill(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = true;

	int cnt = 0;
	for (auto &cow: cows) if (cow.fst == x && cow.scd == y) {
			cnt += 1;
			break;
	}

	while (!q.empty()) {
		auto [cx, cy] = q.front();	q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (valid(nx, ny) && !vis[nx][ny] && !road[cx][cy][i]) {
				vis[nx][ny] = true;
				q.push({nx, ny});

				for (auto &cow: cows) if (cow.fst == nx && cow.scd == ny) {
					cnt += 1;
					break;
				}
			}
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("countcross");
	cin >> N >> K >> R;

	for (int i = 0; i < R; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		if (r1 == r2) {
			if (c1 < c2) {
				road[r1][c1][3] = true;
				road[r2][c2][1] = true;
			} else {
				road[r1][c1][1] = true;
				road[r2][c2][3] = true;
			}
		} else {
			if (r1 < r2) {
				road[r1][c1][2] = true;
				road[r2][c2][0] = true;
			} else {
				road[r1][c1][0] = true;
				road[r2][c2][2] = true;
			}
		}
	}

	for (int i = 0; i < K; ++i) {
		int r, c;
		cin >> r >> c;
		cows.push_back({r, c});
	}

	vector<int> cmpts;
	for (auto &cow: cows) {
		int x = cow.fst, y = cow.scd;
		if (!vis[x][y]) {
			int sz = floodfill(x, y);
			cmpts.push_back(sz);
		}
	}

	ll totCows = 0, distPs = 0;
	for (int sz: cmpts) distPs += sz * totCows, totCows += sz;
	cout << distPs << el;
	return 0;
}
