#include <bits/stdc++.h>
using namespace std;
#define el '\n'

string sternBrocotPath(int m, int n) {
    string path = "";
    // left (0/1), right (1/0)
    int left_m = 0, left_n = 1;
    int right_m = 1, right_n = 0;

    while (true) {
        int middle_m = left_m + right_m;
        int middle_n = left_n + right_n;

        if (middle_m == m && middle_n == n) return path;

        // m * middle_n vs n * middle_m
        // (cross multiplication same as division but more accurate)
        if (m * middle_n > n * middle_m) {
            path += 'R'; // Target is to the right, so move left
            left_m = middle_m;
            left_n = middle_n;
        } else {
            path += 'L';  // Target is to the left, so move right
            right_m = middle_m;
            right_n = middle_n;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int m, n;
    while (cin >> m >> n) {
        if (m == 1 && n == 1) break;
        cout << sternBrocotPath(m, n) << el;
    }

    return 0;
}
