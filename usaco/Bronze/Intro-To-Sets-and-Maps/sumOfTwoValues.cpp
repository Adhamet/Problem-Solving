// CSES
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;  cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        if(mp.count(x - arr[i])) {
            cout << i + 1 << " " << mp[x-arr[i]] << '\n';
            return 0;
        }
        mp[arr[i]] = i + 1;
    }
    cout << "IMPOSSIBLE";

    return 0;
}
