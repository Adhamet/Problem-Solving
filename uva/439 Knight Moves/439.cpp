#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'

using pi = pair<int, int>;

const int oo = 1e9 + 20;
int dist[8][8];
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool valid(int x, int y) {
	return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}

void bfs(int x, int y) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			dist[i][j] = oo;
	
	dist[x][y] = 0;

	queue<pi> q;
	q.push({x, y});
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (valid(nr, nc) && dist[r][c] + 1 < dist[nr][nc]) {
				dist[nr][nc] = dist[r][c] + 1;
				q.push({nr, nc});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string pos1, pos2;
	while (cin >> pos1 >> pos2) {
		array<int, 2> from, to;
		from[0] = pos1[1] - '1'; // row
		from[1] = pos1[0] - 'a'; // column
		to[0] = pos2[1] - '1'; // row
		to[1] = pos2[0] - 'a'; // column

		bfs(from[0], from[1]);
		cout << "To get from " << pos1 << " to " << pos2 << " takes " << dist[to[0]][to[1]] << " knight moves.";
		cout << el;
		cout.flush();
	}

	return 0;
}
