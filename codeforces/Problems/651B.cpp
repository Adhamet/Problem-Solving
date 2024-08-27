#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;  cin >> n;
    map<int, int> freq;
   
    int mx = 0;
    for(int i = 0; i < n; i++) {
        int painting;   cin >> painting;
        freq[painting]++;
        mx = max(mx, freq[painting]);
    }
    cout << n - mx;
    
    return 0;
}
