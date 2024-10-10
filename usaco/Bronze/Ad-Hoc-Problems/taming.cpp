#include <bits/stdc++.h>
using namespace std;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("taming");

    int n;    cin >> n;
    vector<int> v(n);
    for(auto &x: v) cin >> x;

    v[0] = 0;
    for(int i = 0; i < n; i++) if(v[i] != -1) {
        v[i-v[i]] = 0;
    }

    int breakout = 0, uncertain = 0, lastBreakout = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] == 0) { lastBreakout = i; breakout++; }
        if(v[i] != -1 && v[i] != 0 && i-v[i] < lastBreakout) return cout << -1, 0;
    }

    for(int i = 0; i < n; i++) {
        int j = i;
        for(j = i; v[j] == -1; j++);
        if(v[j] == 0) uncertain += j - i;
        i = j;
    }

    cout << breakout << ' ' << breakout + uncertain;
    
    return 0;
}
