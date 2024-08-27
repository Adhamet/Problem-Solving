#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;      cin >> n;
    string s;   cin >> s;
    
    int cows = 0, in=0,a=0,f=0;
    for(int i = 0; i < n; i++) {
        if (s[i] == 'A') a++;
        else if (s[i] == 'I') in++;
        else if (s[i] == 'F') f++;
    }
    if (in > 1) cout << '0';
    else if (in == 1) cout << 1;
    else cout << in + a;

    return 0;
}
