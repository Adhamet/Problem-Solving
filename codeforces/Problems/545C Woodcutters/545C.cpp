#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MAXN = 2e5 + 5;
int n, mem[MAXN][3];
vector<array<int, 2>> h(MAXN);

int solve(int i, int move, int last) {
    if (i >= n) return 0; 
    if (mem[i][move] != -1) return mem[i][move];

    long long op1 = 0, op2 = 0, op3 = 0;
    if (i == 0) op1 = solve(i + 1, 1, h[i][0]) + 1;
    else if (i == n - 1) return 1;
    else {
        op1 = solve(i + 1, 0, h[i][0]);
        if (h[i][0] - h[i][1] > last) op2 = solve(i + 1, 1, h[i][0]) + 1;
        if (h[i][0] + h[i][1] < h[i + 1][0]) op3 = solve(i + 1, 2, h[i][0] + h[i][1]) + 1;
    }

    return mem[i][move] = max({op1, op2, op3});
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i][0] >> h[i][1];
    memset(mem, -1, sizeof(mem));
    cout << solve(0, 0, INT_MAX) << el;
    return 0;
}
