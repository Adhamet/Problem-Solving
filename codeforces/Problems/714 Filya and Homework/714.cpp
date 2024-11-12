#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main() {
    ios_base::sync_with_stdio(0), std::cin.tie(nullptr);
    
    int n, x;
    cin >> n;
    set<int> a;
    for (int i = 0; i < n; i++) cin >> x, a.insert(x);
    if (a.size() < 3) cout << "YES";
    else if (a.size() > 3) cout << "NO";
    else {
        vector<int> b(a.begin(), a.end());
        if (b[1] - b[0] == b[2] - b[1]) cout << "YES";
        else cout << "NO";
    }

    return 0;
}
