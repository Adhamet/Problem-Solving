#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n,m;    cin >> n >> m;
    char grid[n][m];
    bool crossed[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            crossed[i][j] = false;
        }
    }
    
    string word = "";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int r_cell = i+1; r_cell < n; r_cell++) {
                if (grid[i][j] == grid[r_cell][j]) {
                    crossed[i][j] = true;
                    crossed[r_cell][j] = true;
                }
            }
            for(int c_cell = j+1; c_cell < m; c_cell++) {
                if (grid[i][j] == grid[i][c_cell]) {
                    crossed[i][j] = true;
                    crossed[i][c_cell] = true;
                }
            }
            
            if (!crossed[i][j])
                word += grid[i][j];
        }
    }
    cout << word;

    return 0;
}
