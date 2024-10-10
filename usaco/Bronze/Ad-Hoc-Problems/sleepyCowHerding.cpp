#include <bits/stdc++.h>
using namespace std;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("milkorder");

    vector<int> locs;
    for(int i = 0; i < 3; i++) {
        int val;    cin >> val;
        locs.push_back(val);
    }

    sort(locs.begin(),locs.end());

    if(locs[0] == locs[2]-2) cout << 0 << '\n';
    else if( (locs[1] == locs[2]-2) || (locs[0] == locs[1]-2) ) cout << 1 << '\n';
    else cout << 2 << '\n';

    cout << max(locs[2]-locs[1], locs[1]-locs[0]) - 1;
    return 0;
}
