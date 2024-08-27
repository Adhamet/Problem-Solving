#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    long long n,k;      cin >> n >> k;
    long double x1,y1,dist=0;     cin >> x1 >> y1;
    
    while(--n) {
        long double x2,y2;      cin >> x2 >> y2;
        dist += sqrt( pow((x1-x2),2) + pow((y1-y2),2) );
        x1 = x2; y1 = y2;
    }
    dist *= (long double) k;
    dist /= (long double) 50;
    cout << setprecision(9) << fixed << dist;

    return 0;
}
