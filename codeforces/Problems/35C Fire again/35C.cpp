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
int dx[] = { -1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	auto valid = [&](int x, int y) -> bool {
		return x >= 1 && x <= n && y >= 1 && y <= m;
	};

	bool burn[n + 1][m + 1];
	memset(burn, 0, sizeof burn);
	
	int k;
	cin >> k;
	queue<pi> q;
	while (k--) {
		int x, y;
		cin >> x >> y;
		
		burn[x][y] = true;
		q.push({x, y});
	}

	pi lastBurned = {0, 0};
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		lastBurned = {x, y};

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (valid(nx, ny) && !burn[nx][ny]) {
				burn[nx][ny] = true;
				q.push({nx, ny});
			}
		}

	}

	cout << lastBurned.first << " " << lastBurned.second << el;
	return 0;
}
