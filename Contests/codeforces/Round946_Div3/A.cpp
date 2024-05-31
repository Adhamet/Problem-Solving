#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() 
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int t;  cin >> t;
        while(t--) {
                int x,y;       cin >> x >> y;
                int yScreens = (y+1)/2;
                int moreScreens = 0;
                if(y%2 == 0) {
                         x = (x - ( (y+1) / 2 ) * 7);
			if(x>0) moreScreens = ceil(x/15.0);
                } else {
			x = (x - ( y / 2 ) * 7);
                        x = (x - 11);
                        if(x>0) moreScreens = ceil(x/15.0);
                }

                cout << yScreens + moreScreens << '\n';
        }

        return 0;
}

