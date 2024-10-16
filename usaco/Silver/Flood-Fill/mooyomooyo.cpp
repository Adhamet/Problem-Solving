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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, K;
vector<pi> component;
vector<vector<int>> board;
vector<vector<bool>> vis;

void floodFill(int x, int y, int color) {
    vis[x][y] = true;
    component.push_back({x, y});

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < N && ny >= 0 && ny < 10 &&
            !vis[nx][ny] && board[nx][ny] == color) {
            floodFill(nx, ny, color);
        }
    }
}

void applyGravity() {
    for (int col = 0; col < 10; ++col) {
        int emptyRow = N - 1;

        for (int row = N - 1; row >= 0; --row) {
            if (board[row][col] != 0) {
                board[emptyRow][col] = board[row][col];
                if (emptyRow != row) board[row][col] = 0;
                --emptyRow;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    setIO("mooyomooyo");
    cin >> N >> K;
    board.resize(N, vector<int>(10));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            char ch;
            cin >> ch;
            board[i][j] = ch - '0';
        }
    }

    while (true) {
        bool clearedAny = false;

        vis.assign(N, vector<bool>(10, false));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (board[i][j] != 0 && !vis[i][j]) {
                    component.clear();
                    floodFill(i, j, board[i][j]);

                    if (component.size() >= K) {
                        clearedAny = true;
                        for (auto [x, y] : component) {
                            board[x][y] = 0;
                        }
                    }
                }
            }
        }

        if (!clearedAny) break;
        applyGravity();
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
