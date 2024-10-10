#include <bits/stdc++.h>
using namespace std;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("sleepy");

    int cows[105];
    
    int n;    cin >> n;
    for(int i = 0; i < n; i++) cin >> cows[i];

    int ANS = n - 1;
    for(int i = n-2; i>=0; i--) {
        if(cows[i] < cows[i+1]) ANS = i;
        else break;
    }
    cout << ANS << '\n';
    
    return 0;
}
