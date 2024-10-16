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

const int MAXN = 3000;
int grid[MAXN][MAXN], ans = 0;
bool comfy(int r, int c);
void adjust(int r, int c);
void makeUncomfy(int r, int c);

bool comfy(int r, int c){
    bool up = grid[r + 1][c] != 0;
    bool right = grid[r][c + 1] != 0;
    bool down = grid[r - 1][c] != 0;
    bool left = grid[r][c - 1] != 0;
    return (int) up + (int) down + (int) right + (int) left == 3;
}

void adjust(int r, int c){
    if (grid[r][c] != 0 && comfy(r, c)) makeUncomfy(r, c);
    if (grid[r + 1][c] != 0 && comfy(r + 1, c)) makeUncomfy(r + 1, c);
    if (grid[r][c + 1] != 0 && comfy(r, c + 1)) makeUncomfy(r, c + 1);
    if (grid[r - 1][c] != 0 && comfy(r - 1, c)) makeUncomfy(r - 1, c);
    if (grid[r][c - 1] != 0 && comfy(r, c - 1)) makeUncomfy(r, c - 1);
}

void makeUncomfy(int r, int c){
    if (grid[r + 1][c] == 0){
        grid[r + 1][c] = 2, ans++;
        adjust(r + 1, c);
    } else if (grid[r][c + 1] == 0){
        grid[r][c + 1] = 2, ans++;
        adjust(r, c + 1);
    } else if (grid[r - 1][c] == 0){
        grid[r - 1][c] = 2, ans++;
        adjust(r - 1, c);
    } else if (grid[r][c - 1] == 0) {
        grid[r][c - 1] = 2, ans++;
        adjust(r, c - 1);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        r += 1500, c += 1500;
        if (grid[r][c] == 0) grid[r][c] = 1;
        else if (grid[r][c] == 2) grid[r][c] = 1, --ans;
        adjust(r, c);
        cout << ans << el;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
