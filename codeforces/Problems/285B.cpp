#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n,bI,bL;    cin >> n >> bI >> bL;
    int arr[n+2];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    int shuffles=0;
    while(bI != bL) {
        if (shuffles > n) return cout << -1, 0;
        bI = arr[bI];
        shuffles++;
    }
    cout << shuffles;

    return 0;
}
