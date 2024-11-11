#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main() {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    
    int n;
    while (cin >> n && n) {
        vector<array<int, 2>> pts(n);
        for (int i = 0; i < n; i++) {
            cin >> pts[i][0] >> pts[i][1];
        }

        array<int, 2> mdpt;
        if (n % 2 == 0) mdpt = pts[(n / 2)];
        else mdpt = pts[(n - 1) / 2];

        int stan = 0, ollie = 0;
        for (int i = 0; i < n; i++) {
            if (pts[i][0] > mdpt[0] && pts[i][1] > mdpt[1]) stan += 1;
            else if (pts[i][0] < mdpt[0] && pts[i][1] < mdpt[1]) stan += 1;
            else if (pts[i][0] > mdpt[0] && pts[i][1] < mdpt[1]) ollie += 1;
            else if (pts[i][0] < mdpt[0] && pts[i][1] > mdpt[1]) ollie += 1;
        }

        cout << stan << " " << ollie << el;
    }

    return 0;
}
