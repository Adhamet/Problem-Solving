#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    
    int a[n], b[n];
    b[0]=0;
    for(int i = 1; i <= n; i++) {
        int x,y;
        cin >> x >> y;
        a[i] = b[i-1] + 1;
        b[i] = b[i-1] + x * y;
    }
    
    int val;
    while(m--) {
        cin >> val;
        cout << lower_bound(b + 1, b + 1 + n, val) - b << endl;
    }
}
