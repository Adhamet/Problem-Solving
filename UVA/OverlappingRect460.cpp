#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, x1Left, y1Left, x1Right, y1Right, x2Left, y2Left, x2Right, y2Right;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x1Left >> y1Left >> x1Right >> y1Right >> x2Left >> y2Left >> x2Right >> y2Right;
        
        int xL = max(x1Left, x2Left);
        int yL = max(y1Left, y2Left);
        int xR = min(x1Right, x2Right);
        int yR = min(y1Right, y2Right);
        
        if ( i > 0 ) cout << '\n';
        
        if ( xL < xR && yL < yR )
            cout << xL << " " << yL << " " << xR << " " << yR << '\n';
        else
            cout << "No Overlap\n";
    }

    return 0;
}
