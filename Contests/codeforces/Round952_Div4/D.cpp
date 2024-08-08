#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

/* void setIO(string name = "") { */
/*     if (name.size()) { */
/*         freopen((name+".in").c_str(), "r", stdin); */
/*         freopen((name+".out").c_str(), "w", stdout); */    
/*     } */
/* } */

int main()
{
    /* setIO("cowqueue"); */
    adhamet;

    int t;  cin >> t;
    while(t--) {
        int n,m;    cin >> n >> m;
        char grid[n][m];
        int fHR=2e6, sHR=-1, fHC=2e6, sHC=-1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == '#') {
                    if(i < fHR) fHR = i;
                    if(i > sHR) sHR = i;
                    if(j < fHC) fHC = j;
                    if(j > sHC) sHC = j; 
                }
            }
        }

        
        int finalX = ((fHR + sHR) / 2) + 1;
        int finalY = ((fHC + sHC) / 2) + 1;
        cout << finalX << " " << finalY << el;
    }

    return 0;
}
