#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    char ch;
    cin >> ch;
    long double r[10][4];
    int n = 0;
    while(ch != '*') {
        cin >> r[n][0] >> r[n][1] >> r[n][2] >> r[n][3];
        n++;
        cin >> ch;
    }
    
    double x,y;
    int pt=1;
    bool contained;
    cin >> x >> y;
    while(x != 9999.9 && y != 9999.9) {
        contained = false;
        for(int i = 0; i < n; i++) if ( x > r[i][0] && x < r[i][2] && y < r[i][1] && y > r[i][3] ) {
            cout << "Point " << pt << " is contained in figure " << i+1 << '\n';
            contained = true;
        }
        if (!contained) cout << "Point " << pt << " is not contained in any figure\n";
        pt++;
        cin >> x >> y;
    }
    return 0;
}
