#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

const int MAXN = 22;
int M, N;
char map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int mod(int x, int n) {
    return (x + n) % n;
}

int floodFill(int x, int y, char landChar) {
    if (x < 0 || x >= M || visited[x][y] || map[x][y] != landChar) return 0;

    visited[x][y] = true;
    int size = 1;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = mod(y + dy[d], N);
        size += floodFill(nx, ny, landChar);
    }

    return size;
}

int main() {
    while (cin >> M >> N) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                visited[i][j] = false;
            }
        }

        int startX, startY;
        cin >> startX >> startY;
        char landChar = map[startX][startY];

        floodFill(startX, startY, landChar);

        int maxContinentSize = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && map[i][j] == landChar) {
                    int continentSize = floodFill(i, j, landChar);
                    maxContinentSize = max(maxContinentSize, continentSize);
                }
            }
        }

        cout << maxContinentSize << endl;

        string trash;
        getline(cin, trash);
    }

    return 0;
}
