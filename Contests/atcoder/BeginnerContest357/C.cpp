#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vector<vector<char>> grid;

void paintGrid(int x, int y, int k) {
    if(k == 0) return;

    int sz = pow(3, k-1);
    int startX = x + sz;
    int startY = y + sz;

    for(int i = startX; i < startX + sz; i++) {
        for(int j = startY; j < startY + sz; j++) {
            grid[i][j] = '.';
        }
    }

    for(int dx = 0; dx < 3; dx++) {
        for(int dy = 0; dy < 3; dy++) {
            if(dx == 1 && dy == 1) continue; 
            paintGrid(x + dx * sz, y + dy * sz, k - 1);
        }
    }
}

int main() {
    adhamet;

    int k;  
    cin >> k;
    if(k == 0) {
        cout << "#" << endl;
        return 0;
    }

    int sz = pow(3, k);
    grid.resize(sz, vector<char>(sz, '#'));

    paintGrid(0, 0, k);

    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            cout << grid[i][j];
        }
        cout << el;
    }

    return 0;
}
