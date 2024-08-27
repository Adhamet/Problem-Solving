#include <bits/stdc++.h>
using namespace std;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int n, m, k;
bool check(vector<int> order, vector<int> &status) {
    vector<int> cp(n, -1);

    for (int i = 0; i < n; i++) {
        if (order[i] != -1) { cp[order[i]] = i; }
    }

    int sIdx = 0;
    for (int i = 0; i < n && sIdx < m; i++) {
        if (cp[status[sIdx]] != -1) {

            if (i > cp[status[sIdx]]) { return false; }

            i = cp[status[sIdx]];
            sIdx++;
        } else {
            while (i < n && order[i] != -1) { i++; }

            if (i == n) { return false; }

            order[i] = status[sIdx];
            cp[status[sIdx]] = i;
            sIdx++;
        }
    }

    return true;
}

int main() {
    setIO("milkorder");

    cin >> n >> m >> k;

    vector<int> status(m);
    for (int i = 0; i < m; i++) {
        cin >> status[i];
        status[i]--;
    }

    vector<int> order(n, -1);

    for (int i = 0; i < k; i++) {
        int cow, pos;
        cin >> cow >> pos;

        order[--pos] = --cow;

        if (cow == 0) {
            cout << pos + 1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (order[i] == -1) {
            order[i] = 0;
            if (check(order, status)) {
                cout << i + 1 << endl;
                break;
            }
            order[i] = -1;
        }
    }
    
    return 0;
}
